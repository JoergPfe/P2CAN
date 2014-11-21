//============================================================================
// Name        : datamanager.cpp
// Author      : Johannes Marstatt
// Version     :
// Copyright   :
// Description :
//============================================================================

#include "datamanager.h"

datamanager::datamanager() {
    dt.set_time_ms(75);
    dt.callback = std::bind(&datamanager::timerelapsed , this,std::placeholders::_1);
    dt.start();
}

dataIterator datamanager::find(int32_t id) {
    return std::find(datalist.begin(), datalist.end(), id);
}

//! Adding a Datapoint definition
/*!
  \param id ID of an added Datapoint
  \return error result
 */
int datamanager::add_dp(int32_t id) {
    if (datalist.empty() == false) {
        if (this->find(id) != this->datalist.end()) {
            std::cout << "duplicate id:" << id << std::endl;
            return -1;
        }
    }
    datalist.push_back(data(id));
    return 0;
}

//! Sends a Datapoint over all of his configured channels
/*!
  \param id ID of Datapoint
  \return error result
 */
int datamanager::send_val(int32_t id) {
    dataIterator findIter = this->find(id);
    if (findIter != this->datalist.end()) {
        findIter->send();
    } else {
        std::cout << "ID not found:" << id << std::endl;
    }
    return 0;
}

//! Updating a Datapoints Value
/*!
  \param id ID of Datapoint
  \param value Value
  \return error result
*/
int datamanager::update_val(int32_t id, int64_t value) {
    dataIterator findIter = this->find(id);
    if (findIter != this->datalist.end()) {
        return findIter->value = value;
    } else {
        std::cout << "ID not found:" << id << std::endl;
    }
    return 0;
}

//! Adding a Channel and a Cycletime to a Datapoint definition
/*!
  \param id ID of an added Datapoint
  \param chan Pointer to a Channel 
  \param cycletime Value is send over "chan" every cycletime milliseconds
  \return error result
 */
int datamanager::add_dp_chan(int32_t id, IChannel *chan, int cycletime) {
    dataIterator findIter = this->find(id);
    if (findIter != this->datalist.end()) {
        findIter->add_chan(chan);
        if (cycletime != 0) {
            TimerList.push_back(std::pair<int32_t, IChannel*>(id, chan));
        }
    } else {
        std::cout << "ID not found:" << id << std::endl;
    }
    return 0;
}

//! Callbackfunction for timer event
/*!
  \param DeadlineTimer*
 */
void datamanager::timerelapsed(DeadlineTimer *timerobj) {
  //  std::cout << "datamanager::timerelapsed timeout: " << timerobj->get_time_ms() << " ms"<< std::endl;
    for (unsigned int i = 0; i < TimerList.size(); i++) {
        this->find(TimerList.at(i).first)->send(TimerList.at(i).second);
    }
}

//! Return dp value by ID
/*!
  \param id
  \return value
 */
int64_t datamanager::get_val(int32_t id) {
    dataIterator findIter = this->find(id);
    if (findIter != this->datalist.end()) {
        return findIter->value;
    } else {
        std::cout << "ID not found:" << id << std::endl;
    }
    return 0;
}

//! Print a list of currently configured Datapoints with values
/*!
  \return none
*/
void datamanager::list() {
    std::cout << "List:" << std::endl;
    for (dataIterator Iter = this->datalist.begin(); Iter != this->datalist.end(); Iter++) {
        std::cout << "ID: " << Iter->id << std::endl;
        std::cout << "Value: " << Iter->value << std::endl;
    }
    std::cout << std::endl << std::endl;
}
