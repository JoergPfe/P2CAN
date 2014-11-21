/*
 * canChannel.h
 *
 *  Created on: 22.09.2014
 *      Author: andreas
 */


#ifndef CANCHANNEL_H_
#define CANCHANNEL_H_

#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include <vector>
#include <string>
#include <iostream>
#include <thread>

#include "IDatamanager.h"
#include "IChannel.h"


class canChannel : public IChannel {
public:
    canChannel(std::string canDevice, IDatamanager *dm);
   virtual ~canChannel();
    int send(int32_t id, int64_t value);
    std::string canDevice;

private:
    std::thread runner;
    int s;
    IDatamanager *dm;
    void empfangen();
    struct ifreq ifr;
    struct sockaddr_can addr;
    struct can_frame frame;
    std::vector<unsigned char> intToBytes(int64_t value);
};

#endif /* CHANNEL_H_ */
