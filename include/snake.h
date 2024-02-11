#pragma once

#include "const.h"
#include "intvector.h"


class Snake {

public:
    Snake(void);
    Snake(unsigned char row, unsigned char col);

    void move(void);
    void turn(void);

    Vector position;
    Vector direction;

    unsigned int length;

private:

};