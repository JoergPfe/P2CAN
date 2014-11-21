/* 
 * File:   DeadlineTimer.cpp
 * Author: jm
 * 
 * Created on September 24, 2014, 4:12 PM
 */



#include "DeadlineTimer.h"
#include <unistd.h>

DeadlineTimer::DeadlineTimer() {
	running = false;
	cycletime = 0;

}
DeadlineTimer::DeadlineTimer(int cycletime) {
	running = false;
	if (cycletime >= 0)
        this->cycletime = cycletime;
}

DeadlineTimer::DeadlineTimer(const DeadlineTimer& orig) {
}

DeadlineTimer::~DeadlineTimer() {
}

void DeadlineTimer::run() {
    while (running) {
        usleep(cycletime * 1000);
        callback(this);
    }
}

void DeadlineTimer::set_time_ms(int ms) {
    cycletime = ms;
}

int DeadlineTimer::get_time_ms() {
    return this->cycletime;
}

void DeadlineTimer::start() {
    if (!running) {
        running = true;
        runner = std::thread(&DeadlineTimer::run, this);
    }
}

void DeadlineTimer::stop() {
    if (running) {
        running = false;
        runner.join();
    }
}
