/* 
 * File:   Idatamanager.h
 * Author: jm
 *
 * Created on September 24, 2014, 10:39 AM
 */

#ifndef IDATAMANAGER_H
#define	IDATAMANAGER_H

#include "IChannel.h"

/// Interface datamanger for interaction with datamanger class
class IDatamanager {
public:
    
    virtual int add_dp_chan(int32_t id,IChannel *chan,int cycletime)=0;
    virtual int add_dp(int32_t id)=0;
    
    virtual int send_val(int32_t id)=0;
    virtual int update_val(int32_t id, int64_t value)=0;
    virtual int64_t get_val(int32_t id)=0;
};

#endif	/* IDATAMANAGER_H */

