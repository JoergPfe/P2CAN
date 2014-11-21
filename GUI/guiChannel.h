/*
 * guiChannel.h
 *
 *  Created on: 24.09.2014
 *      Author: andreas
 */

#ifndef GUICHANNEL_H_
#define GUICHANNEL_H_

#include "../IDatamanager.h"
#include "../IChannel.h"

class guiChannel : public IChannel {
public:
    pthread_t thread1;
    guiChannel();
    int send(int32_t id, int64_t value);
};

#endif /* GUICHANNEL_H_ */
