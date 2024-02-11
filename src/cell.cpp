#include "cell.h"
#include "debug.h"


Cell::Cell() {
    set_state(EMPTY);
}


Cell::Cell(Vector position, celltype type, unsigned int counter) {
    set_state(type, counter);
    this->grid_position = position;
}


void Cell::set_state(celltype type, unsigned int counter) {
    this->type = type;
    this->counter = counter;
}


void Cell::set_state(celltype type) {
    this->type = type;
    this->counter = UINT_ZERO;
}


void Cell::update(void) {
    if (counter > UINT_ZERO) {
        counter--;
    }
    else if (type == SNAKE_HEAD || type == SNAKE_BODY) {
        set_state(EMPTY);
    }
}


void Cell::render(Vector position) {
    Vector screen_position = grid2screen(position);
    
    switch (type) {
    case SNAKE_BODY:
        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;
    case SNAKE_HEAD:
        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;
    case APPLE:
        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE, COLORS::APPLE);
        break;
    default:
        break;   
    }
}


Vector Cell::grid2screen(Vector position) {
    unsigned char col = grid_position.x;
    unsigned char row = grid_position.y;
    return Vector(col * CELL_SIZE + CELL_GAP, row * CELL_SIZE + CELL_GAP) + position;
}