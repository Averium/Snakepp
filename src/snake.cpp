#include "snake.h"


Snake::Snake(void) {
    position = Vector(0U, 0U);
    direction = DIRECTION::RIGHT;
    length = STARTING_LENGTH;
}


Snake::Snake(unsigned char row, unsigned char col) {
    position = Vector((int)row, (int)col);
    direction = DIRECTION::RIGHT;
    length = STARTING_LENGTH;
}


void Snake::move(void) {
    position += direction;
}


void Snake::turn(Vector direction) {
    this->direction = direction;
}