#pragma once

#include "const.h"
#include "integer_vector.h"
#include <queue>


class Snake {

public:
    Snake(void);
    Snake(unsigned char row, unsigned char col);

    void move(void);
    void turn(Vector new_direction);
    void change_direction(void);

    Vector position;
    Vector direction;

    unsigned int length;

private:

    std::queue<Vector> turn_queue;

};