/* 
 * File:   Communicate.h
 * Author: Jörg Pfendert
 *
 * Created on 23. September 2014, 22:25
 */

#ifndef SOCKETIO_H
#define	SOCKETIO_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include <vector>
#include <iostream>

#include <pthread.h>
#include "IDatamanager.h"
#include "datamanager.h"
#include "IChannel.h"
#include "CalcCanFrame.h"


//new
#include <assert.h>
#include <stddef.h>
#include <thread>

//-

#define BUF 1024
#define LEN 2
#define UDS_FILE "/tmp/sock.uds"

class SocketIO {
public:
    SocketIO(datamanager *dm);
    SocketIO(const SocketIO& orig);
    virtual ~SocketIO();

    uint64_t decode_unsigned_varint( const uint8_t *const data, int &decoded_bytes);
    int64_t decode_signed_varint( const uint8_t *const data, int &decoded_bytes );



    typedef unsigned int uint;
    typedef unsigned char uchar;

  int create_socket;
  unsigned char *buffer;
  struct sockaddr_un address;
  int size;
  void connectToSocket();
  void receiveData();
  void sendData();
  void writeToVelocity(uint64_t meterProS);
  void writeToRpm(uint64_t rpm);
  void writeToFuel(uint64_t fuel);


  std::thread runner;

  IDatamanager *dm;
  CalcCanFrame ccf;


private:

};

#endif	/* COMMUNICATE_H */

