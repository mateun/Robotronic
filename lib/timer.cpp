//
// Created by mgrus on 04/07/2021.
//
#include "timer.h"

Timer::Timer() {
    _freq = SDL_GetPerformanceFrequency();
    _lastDurationInSeconds = 0;
    _lastStart = 0;
}

void Timer::start() {
    _lastStart = SDL_GetPerformanceCounter();
}

void Timer::stop() {
    Uint64 stopTime = SDL_GetPerformanceCounter();
    Uint64 dur = stopTime - _lastStart;
    _lastDurationInSeconds =  (double) dur / _freq;
}

double Timer::getDurationInSeconds() {
    return _lastDurationInSeconds;
}

Uint64 Timer::getDurationInMicroseconds() {
    return _lastDurationInSeconds * 1000 * 1000;
}

Uint64 Timer::getDurationInMilliseconds() {
    return _lastDurationInSeconds * 1000;
}


