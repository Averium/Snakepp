#include "raylib.h"
#include "timer.h"


Timer::Timer() {
    this->period = FLOAT_ZERO;
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