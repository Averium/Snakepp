#pragma once

#include <queue>

#include "const.hpp"
#include "grid.hpp"
#include "timer.hpp"


class Snake {

public:
    Snake(void);
    Snake(Grid& grid, Vector start_pos, unsigned int delay_ms, unsigned int length);

    unsigned int get_length(void) const;
    void increment_length(void);

    void set_dead(void);
    bool is_dead(void) const;

    bool ready_to_move(void);
    bool move(bool walls);
    void turn(Vector new_direction);
    void change_direction(void);
    void set_delay(unsigned int delay_ms);

    Vector position;
    Vector direction;

private:

    unsigned int length;
    bool dead;

    Timer move_timer;
    std::queue<Vector> turn_queue;

};