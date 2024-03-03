#pragma once

#include <queue>

#include "const.hpp"
#include "grid.hpp"
#include "timer.hpp"


class Snake {

public:
    Snake(void);
    Snake(Grid* grid, Vector start_pos, unsigned int delay_ms, unsigned int length);

    bool ready_to_move(void);
    void move(void);
    void turn(Vector new_direction);
    void change_direction(void);
    void set_delay(unsigned int delay_ms);

    Vector position;
    Vector direction;

    unsigned int length;
    bool dead;

private:

    Timer move_timer;
    std::queue<Vector> turn_queue;

};