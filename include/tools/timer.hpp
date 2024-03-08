#pragma once

#include "const.hpp"


class Timer {

public:
    Timer(void);
    Timer(double period);

    void set(double new_period);
    void reset(void);
    bool tick(void);

private:
    double period;
    double statemark;

};