/* 
 * File:   LoggingChannel.cpp
 * Author: bpse_sose14
 * 
 * Created on 29. September 2014, 08:54
 */

#include "LoggingChannel.h"

#include <iostream>

void runnerService2();


LoggingChannel::LoggingChannel() {
        const char *message = "LoggingThread";
        int ret1 = pthread_create(&thread2, NULL, runnerService2, (void*) message);
    if (ret1) {
        printf("Error");
    }
}


void runnerService2(){
    
}

LoggingChannel::send(int32_t id, int64_t value){
//    printf("this is a Message from LoggingChannel id = %x, value %lx");
}

LoggingChannel::~LoggingChannel() {
}

