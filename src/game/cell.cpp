#include "game/cell.hpp"
#include "debug.hpp"


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
    this->counter = CONST::UINT_ZERO;
}


void Cell::update(void) {
    if (counter > CONST::UINT_ZERO) {
        counter--;
    }
    else if (type == SNAKE_HEAD || type == SNAKE_BODY) {
        set_state(EMPTY);
    }
    
    if (type == SNAKE_NEW) {
        set_state(SNAKE_HEAD, counter);
    }
    else if (type == SNAKE_HEAD) {
        set_state(SNAKE_BODY, counter);
    }
}


void Cell::render(Vector position, Vector snake_direction) {
    Vector screen_position = grid2screen(position);
    Vector c, c1, c2, shift;

    unsigned int CELL_SIDE = CONST::CELL_SIZE - CONST::CELL_GAP * 2;

    switch (type) {
    case SNAKE_HEAD:

        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE,COLORS("SNAKE"));

        c = screen_position + Vector(CELL_SIDE / 2, CELL_SIDE / 2);
        shift = Vector(snake_direction.y, snake_direction.x) * (CELL_SIDE / 4);
        c1 = c + shift + snake_direction * (CELL_SIDE / 4);
        c2 = c - shift + snake_direction * (CELL_SIDE / 4);

        DrawRectangle(c1.x - CELL_SIDE / 6, c1.y - CELL_SIDE / 6, CELL_SIDE / 3, CELL_SIDE / 3, COLORS("PATTERN"));
        DrawRectangle(c2.x - CELL_SIDE / 6, c2.y - CELL_SIDE / 6, CELL_SIDE / 3, CELL_SIDE / 3, COLORS("PATTERN"));
        break;
    case SNAKE_BODY:
        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE, COLORS("SNAKE"));
        DrawRectangle(
            screen_position.x + CELL_SIDE / 4,
            screen_position.y + CELL_SIDE / 4,
            CELL_SIDE / 2,
            CELL_SIDE / 2,
            COLORS("PATTERN")
        );
        break;
    case APPLE:
        DrawRectangle(screen_position.x, screen_position.y, CELL_SIDE, CELL_SIDE, COLORS("APPLE"));
        break;
    default:
        break;   
    }
}


Vector Cell::grid2screen(Vector position) {
    unsigned char col = grid_position.x;
    unsigned char row = grid_position.y;
    return Vector(col * CONST::CELL_SIZE + CONST::CELL_GAP, row * CONST::CELL_SIZE + CONST::CELL_GAP) + position;
}