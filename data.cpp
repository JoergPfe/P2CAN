/* 
 * File:   data.cpp
 * Author: jm
 * 
 * Created on September 22, 2014, 12:38 PM
 */

#include "data.h"


data::data(int32_t id) {
    this->id=id;
    value=0;
    cycletime=0;
}


data::~data() {
}

int data::add_chan(IChannel *chan){
	this->chan.push_back(chan);
	return 0;
}

int data::send(IChannel *ch){
	ch->send(this->id,this->value);
	return 0;
}

int data::send(){
	for(unsigned int i = 0; i<chan.size(); i++){
		this->send(chan.at(i));
	}
	return 0;
}

bool data::operator ==(const int32_t& id) {
    return this->id == id;
}


//nothing new