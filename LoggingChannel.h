/* 
 * File:   LoggingChannel.h
 * Author: bpse_sose14
 *
 * Created on 29. September 2014, 08:54
 */

#ifndef LOGGINGCHANNEL_H
#define	LOGGINGCHANNEL_H

#include "IDatamanager.h"
#include "IChannel.h"

class LoggingChannel : public IChannel {
public:
    pthread_t thread2;
    LoggingChannel();
    int send(int32_t id, int64_t value);
    virtual ~LoggingChannel();
private:

};

#endif	/* LOGGINGCHANNEL_H */

