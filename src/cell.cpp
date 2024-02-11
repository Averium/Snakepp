#include "cell.h"
#include "debug.h"


Cell::Cell() {
    set_state(EMPTY, 0U);
}


Cell::Cell(celltype type, unsigned int counter) {
    set_state(type, counter);
}


void Cell::set_state(celltype type, unsigned int counter) {
    this->type = type;
    this->counter = counter;
    print(counter);
}


void Cell::update(void) {
    if (counter > 0U) {
        counter--;
    }
    else {
        counter = 0U;
        type = EMPTY;
    }
}


void Cell::render(unsigned char row, unsigned char col) {
    std::vector screen_pos = grid2screen(row, col);
    
    switch (type) {

    case SNAKE_BODY:
        DrawRectangle(screen_pos[0], screen_pos[1], CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;
        
    case SNAKE_HEAD:
        DrawRectangle(screen_pos[0], screen_pos[1], CELL_SIDE, CELL_SIDE, COLORS::SNAKE);
        break;

    case APPLE:
        DrawRectangle(screen_pos[0], screen_pos[1], CELL_SIDE, CELL_SIDE, COLORS::APPLE);
        break;

    default:
        break;
        
    }
}


std::vector<unsigned int> Cell::grid2screen(unsigned char row, unsigned char col) {
    return {col * CELL_SIZE - CELL_GAP, row * CELL_SIZE - CELL_GAP};
}