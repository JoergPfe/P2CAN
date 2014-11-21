//============================================================================
// Name        : channelInterface.h
// Author      : Andreas Schroll
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef CANINTERFACE_H_
#define CANINTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

/// Interface Channel for interaction with Channels class
class IChannel {
	public:
		//virtual ~IChannel();
		virtual int send(int32_t id, int64_t value) = 0;

	private:

};

#endif
