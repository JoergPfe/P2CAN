/* 
 * File:   DeadlineTimer.h
 * Author: jm
 *
 * Created on September 24, 2014, 4:12 PM
 */

#ifndef DEADLINETIMER_H
#define	DEADLINETIMER_H

#include <chrono>
#include <thread>
#include <iostream>

class DeadlineTimer {
public:
    DeadlineTimer();
    DeadlineTimer(int);
    DeadlineTimer(const DeadlineTimer& orig);
    virtual ~DeadlineTimer();
    void start();
    void stop();
    std::function<void(DeadlineTimer*) > callback;
    void set_time_ms(int ms);
    int get_time_ms();
private:
    void run();
    std::thread runner;
    int cycletime;
    bool running;
};

#endif	/* DEADLINETIMER_H */

