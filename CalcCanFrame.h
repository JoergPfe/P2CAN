/*
 * CalcCanFrame.h
 *
 *  Created on: 26.09.2014
 *      Author: Jörg Pfendert
 */

#ifndef CALCCANFRAME_H_
#define CALCCANFRAME_H_

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

class CalcCanFrame {
public:
	CalcCanFrame();
	virtual ~CalcCanFrame();


	 uint64_t calcVelocity(uint64_t meterProS);
	 uint64_t calcRpm(uint64_t rpm);
	 uint64_t calcFuel(uint64_t fuel);

	 bool emptyFuel = false;




};

#endif /* CALCCANFRAME_H_ */
