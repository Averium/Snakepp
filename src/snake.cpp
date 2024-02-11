#include "snake.h"
#include "debug.h"


Snake::Snake(void) {
    position = Vector(UINT_ZERO, UINT_ZERO);
    direction = DIRECTION::RIGHT;
    length = STARTING_LENGTH;
}


Snake::Snake(unsigned char row, unsigned char col) {
    position = Vector((int)row, (int)col);
    direction = DIRECTION::RIGHT;
    length = STARTING_LENGTH;
}


void Snake::move(void) {
    Vector new_position = position + direction;

    if (new_position.x > (int)GRID_COLUMNS - 1) { new_position.x = 0; }
    if (new_position.x < 0) { new_position.x = (int)GRID_COLUMNS - 1; }
    if (new_position.y > (int)GRID_ROWS - 1) { new_position.y = 0; }
    if (new_position.y < 0) { new_position.y = (int)GRID_ROWS - 1; }

    position = new_position;
}


void Snake::turn(Vector new_direction) {
    turn_queue.push(new_direction);
    if (turn_queue.size() > 2) {
        turn_queue.pop();
    }
}


void Snake::change_direction(void) {
    if (turn_queue.size() > UINT_ZERO) {
        Vector new_direction = turn_queue.front();

        if (new_direction != -direction) {
            direction = new_direction;
        }

        turn_queue.pop();
    }
}