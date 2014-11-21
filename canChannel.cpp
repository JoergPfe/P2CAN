/*
 * canChannel.cpp
 *
 *  Created on: 22.09.2014
 *      Author: andreas
 */

#include "canChannel.h"

canChannel::canChannel(std::string canDevice, IDatamanager *dm) {

    this->canDevice = canDevice;
    this->dm = dm;
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("socket");
    }
    //	int recv_own_msgs = 0; /* 0 = disabled (default), 1 = enabled */
    //  setsockopt(s, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs));

    strcpy(ifr.ifr_name, this->canDevice.c_str());

    if (ioctl(s, SIOCGIFINDEX, &ifr) < 0) {
        perror("SIOCGIFINDEX");
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr*) &addr, sizeof (addr)) < 0) {
        perror("bind");
    }
    runner = std::thread(&canChannel::empfangen, this);
}

canChannel::~canChannel() {
}

//! convert Int64 to vector of Byte

/*!
 * \param value to convert
 * \return vector of bytes
 */
std::vector<unsigned char> canChannel::intToBytes(int64_t value) {
    std::vector<unsigned char> arrayOfByte(8);
    for (int i = 0; i < 8; i++)
        arrayOfByte[7 - i] = (value >> (i * 8));
    return arrayOfByte;
}


//! receive CAN-frames and update the value in datamanager

/*!
 * \return none
 */
void canChannel::empfangen() {
    while (1) {
        struct can_frame inframe;

        ssize_t readsize = read(s, &inframe, sizeof (struct can_frame));
        if (readsize < 0) {
            perror("Error: ");

        }

        //printf("%x # %x %x %x %x %x %x %X %x\n", inframe.can_id, inframe.data[0], inframe.data[1], inframe.data[2], inframe.data[3], inframe.data[4], inframe.data[5], inframe.data[6], inframe.data[7]);
        int64_t a = 0;
        for (int i = inframe.can_dlc - 1; i >= 0; i--) {

            a += (((int64_t) inframe.data[i]) << (8 * (7 - i)));
        }
        dm->update_val(inframe.can_id, a);
    }
}


//! send a canframe

/*!
 * \param CAN-frame ID
 * \param CAN-frame value
 * \return error result
 */
int canChannel::send(int32_t id, int64_t value) {
    frame.can_id = id;
    std::vector<unsigned char> vectorOfByte = intToBytes(value);
    for (int i = 0; i < 8; i++) {
        frame.data[i] = vectorOfByte[i];
    }
    frame.can_dlc = 8;

    if (write(s, &frame, sizeof (frame)) < 0) {
        perror("WRITE");
    }
    return 0;
}
