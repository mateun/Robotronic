//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_TIMER_H
#define ROBOTRONIC_TIMER_H

#include <SDL.h>

class Timer {
public:
    Timer();
    void start();
    void stop();
    double getDurationInSeconds();
    Uint64 getDurationInMicroseconds();
    Uint64 getDurationInMilliseconds();


private:
    Uint64 _freq;
    Uint64 _lastStart;
    double _lastDurationInSeconds;
};

#endif //ROBOTRONIC_TIMER_H
