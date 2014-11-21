//============================================================================
// Name        : datamanager.h
// Author      : Johannes Marstatt
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef DATAMANAGER_H
#define	DATAMANAGER_H

#include <exception>
#include <algorithm>
#include <iostream>

#include "IDatamanager.h"
#include "IChannel.h"
#include "data.h"
#include "DeadlineTimer.h"

typedef std::vector<data>::iterator dataIterator;

class datamanager : public IDatamanager {
public:
    datamanager();
    int add_dp_chan(int32_t id, IChannel *chan, int32_t cycletime);
    int add_dp(int32_t id);
    int send_val(int32_t id);
    int update_val(int32_t id, int64_t value);
    int64_t get_val(int32_t id);
    void list();
    
private:
    void timerelapsed(DeadlineTimer*);
    std::vector<std::pair<int32_t, IChannel*> > TimerList;
    std::vector<data> datalist;
    DeadlineTimer dt;
    dataIterator find(int32_t id);
};

#endif	/* DATAMANAGER_H */

//nothing