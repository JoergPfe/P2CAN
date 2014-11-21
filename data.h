/* 
 * File:   data.h
 * Author: jm
 *
 * Created on September 22, 2014, 12:38 PM
 */

#ifndef DATA_H
#define	DATA_H

#include <string>
#include <stdint.h>
#include <vector>
#include "IChannel.h"

class data {
public:
    data(int32_t);
    virtual ~data();    
    int32_t id;

    int64_t value;
    int cycletime;
    std::string name;
    std::string comment;
    bool operator==(int32_t const& id);  
    int send(IChannel *ch);
    int send();
    int add_chan(IChannel *chan);
private:
    std::vector<IChannel*> chan;

};



#endif	/* DATA_H */

