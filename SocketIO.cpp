/*
 * File:   Communicate.cpp
 * Author: Jörg Pfendert
 * 
 * Created on 23. September 2014, 22:25
 */
#include "canChannel.h"
#include "SocketIO.h"

//new
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <math.h>
//-

typedef unsigned int uint;
typedef unsigned char uchar;

typedef struct Tuple Tuple;
struct Tuple {
	uint32_t velocity;
	uint32_t rpm;
	uint32_t fuel;
};

int unmarshalpkg(const unsigned char *buf, Tuple *result);

SocketIO::SocketIO(datamanager *dm) {
	this->dm = dm;
	this->connectToSocket();
	runner = std::thread(&SocketIO::receiveData,this);
}

SocketIO::SocketIO(const SocketIO& orig) {
}

SocketIO::~SocketIO() {

}





void SocketIO::connectToSocket(){
    buffer = (char*)malloc (BUF);

    if((create_socket=socket(PF_LOCAL, SOCK_STREAM, 0)) > 0)
    printf ("Socket wurde angelegt\n");
        address.sun_family = AF_LOCAL;
        strcpy(address.sun_path, UDS_FILE);


        if (connect ( create_socket,
                (struct sockaddr *) &address,
                sizeof (address)) == 0)
    printf ("Verbindung mit dem Server hergestellt\n");
  else  printf ("KEINE Verbindung hergestellt\n");


}

/*
 * Get data continious (every 200ms) from FPGA (Unix)Socket
 * bytes from socket are in "varint"-Format <<-google
 * first two bytes from read is for the length of the next read
 * length = [0] | [1]
 *  socketData = {velocitiy, rpm, fuel}
 */


void SocketIO::receiveData(){

	while(1){

		//sendData();
		size = read(create_socket, buffer, 2);


    uint16_t length = (uint16_t) buffer[0];
    length = length << 8;
    length = length + (uint16_t) buffer[1];

	Tuple *socketData = new Tuple;

	size = read(create_socket, buffer+2, length);
	int z =  unmarshalpkg(buffer, socketData);

	dm->update_val(0x200, ccf.calcVelocity(socketData->velocity));
	dm->update_val(0x308, ccf.calcRpm(socketData->rpm));
	dm->update_val(0x608, ccf.calcFuel(socketData->fuel));

	usleep(200*1000);
	}
}


void SocketIO::sendData(){


        send(create_socket, "a", 1, 0);
}




void* readuvarint(const void *buf, size_t n, uint64_t *out)
{
	const uchar *p = (uchar*) buf;
	uint64_t x = 0;
	uint s = 0;
	int i;
	uint8_t b;

	for (i=0; n-i; i++) {
		b = *p++;
		if (b < 0x80) {
			if (i>9 || (i==9 && b>1))
				return NULL;

			*out = x | (uint64_t)b<<s;
			return (void*)p;
		}
		x |= (b&0x7f) << s;
		s+=7;
	}

	return NULL;
}

/*
 * Decode varint-format from Buffer
 * to get struct with {velocity, rpm, fuel}
 *
 *
 */
int unmarshalpkg(const unsigned char *buf, Tuple *result)
{

	uint64_t velocity, rpm, fuel;
	uint16_t pkglen = buf[0]<<8 | buf[1]; // Get length form first 2 bytes of Buffer

	const unsigned char *workBuffer = buf+2;
	const unsigned char *oldBuffer = workBuffer;

	workBuffer = readuvarint(workBuffer, pkglen, &velocity);
	if(workBuffer == NULL) printf("not a varint");

	pkglen -= (workBuffer-oldBuffer); // Anzahl gelesener Bytes abziehen

	oldBuffer = workBuffer;
	workBuffer = readuvarint(workBuffer, pkglen, &rpm);
	if(workBuffer == NULL) printf("not a varint");
	pkglen -= (workBuffer-oldBuffer); // Anzahl gelesener Bytes abziehen

	oldBuffer = workBuffer;
	workBuffer = readuvarint(workBuffer, pkglen, &fuel);
	if(workBuffer == NULL) printf("not a varint");


	// drei Werte erfolgreich gelesen und in x, y, z

	*result = (Tuple){
		.velocity = velocity,
		.rpm = rpm,
		.fuel = fuel
	};

	return 0; // success
}







