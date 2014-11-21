/*
 * CalcCanFrame.cpp
 *
 *  Created on: 26.09.2014
 *      Author: Jörg Pfendert
 */

#include "CalcCanFrame.h"
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

CalcCanFrame::CalcCanFrame() {


}

CalcCanFrame::~CalcCanFrame() {
	// TODO Auto-generated destructor stub
}


/* ! Calc  value for for VELOCITY CAN FRAME ( ID 0x200)
 *   shift meter/perS to the right position
 *   [0x200]  [0] [1] [2] [3] [X] [X] [6] [7]
 *   velocity * 2.4 (=>Mph)
 *   Data Byte [4] : velocity / 5
 *   Data Byte [5] : ( 255*(velocity % 255) ) / 5
 * *!
 *  \param value from UnixSocket in meterProS
 * \return uint64_t with shifted bits
 */

uint64_t CalcCanFrame::calcVelocity(uint64_t meterProS){

	//printf("Velocity: %llu\n", meterProS);
	uint64_t highbyte;
	int lowbyte;
	double calc = meterProS;

	calc = (meterProS*2.24) ;

	std::cout<<"Velocity: "<<calc<<std::endl;


	meterProS = round(calc);
	highbyte = meterProS / 5;

	lowbyte = meterProS % 5;
	lowbyte= 255*lowbyte/5;

	meterProS = highbyte <<(8*1);
	meterProS+= lowbyte;
	meterProS = meterProS<<(8*2);

	return meterProS;
}


/*!  Calc  value for for RPM CAN FRAME ( ID 0x308)
 *   shift rounds/perMin to the right position
 *   [0x308]  [0] [X] [X] [3] [4] [5] [6] [7]
 *   Data Byte [1] : rpm / 250
 *   Data Byte [2] : (250 * (rpm % 250) ) / 255
 *
 * example rpm = 3123
 * Data Byte [1] = 3123 / 250 = 12
 * Data Byte [2] = ( 250 * (123) ) /255 = 120
 * Frame id 0x308 includes fuel indicator light in Data Byte[3] Bit0
 * 
 *	\param Rounds per minute
 *  return uint64_t with shifted bits
 */

uint64_t CalcCanFrame::calcRpm(uint64_t rpm){
	printf("RPM: %llu\n", rpm);

	uint64_t highbyte;
	int lowbyte;
	double calc = rpm;

	calc = (rpm*1) ;
	rpm = round(calc);
	highbyte = rpm / 250;

	lowbyte = rpm % 250;
	lowbyte= 250*lowbyte/250;

	rpm = highbyte <<(8*1);
	rpm+= lowbyte;
	rpm = rpm<<(8*5);

//Fuel light on/off
	if(emptyFuel==true){
		rpm = rpm | ((int64_t)1 <<( 8*4)); //light on
	}
	else{
		rpm = rpm | ((int64_t)0 <<( 8*4)); //light off
		emptyFuel = false;
				}


	return rpm;
}


//GIT TEST

//! Calc  value for for Fuel Can Frame ( ID 0x608) <br>
/*! because gasometer is analog and there is no ID <br>
*    we use the cooling indicator as gasometer <br>
*    Data Byte [0] : fuel + 80 \n
*    [0x608]  [0] [1] [2] [3] [4] [5] [6] [7] \n
*    \param  fuel in Liter
*    \return uint64_t with shifted bits
*/

uint64_t CalcCanFrame::calcFuel(uint64_t fuel){

	printf("Fuel: %llu\n", fuel);
	if (fuel <=10){
		emptyFuel = true;
			}
	else {
	emptyFuel = false;
		 }
	fuel = fuel + 80;
	fuel = fuel <<(8*7);


return fuel;
}
