#include "raylib.hpp"
#include "timer.hpp"


Timer::Timer() : period(CONST::FLOAT_ZERO) {}


Timer::Timer(double period) : period(period) {}


void Timer::set(double new_period) {
    this->period = new_period;
}


bool Timer::tick(void) {
    double now = GetTime();

    if (now - this->statemark > this->period) {
        this->statemark = now;
        return true;
    }
    else {
        return false;
    }
}