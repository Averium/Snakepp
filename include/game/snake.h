#pragma once

#include <queue>

#include "const.h"
#include "grid.h"


class Snake {

public:
    Snake(void);
    Snake(Vector start_pos, Grid* grid);

    void move(void);
    void turn(Vector new_direction);
    void change_direction(void);

    Vector position;
    Vector direction;

    unsigned int length;
    bool dead;

private:

    std::queue<Vector> turn_queue;

};