#pragma once

#include "const.hpp"


class Timer {

public:
    Timer(void);
    Timer(double period);

    bool tick(void);

private:
    double period;
    double statemark;

};