#pragma once

#include "const.h"
#include "integer_vector.h"


class Snake {

public:
    Snake(void);
    Snake(unsigned char row, unsigned char col);

    void move(void);
    void turn(Vector direction);

    Vector position;
    Vector direction;

    unsigned int length;

private:

};