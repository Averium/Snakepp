#include "raylib.hpp"
#include "timer.hpp"


Timer::Timer() {
    this->period = CONST::FLOAT_ZERO;
}


Timer::Timer(double period) {
    this->period = period;
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