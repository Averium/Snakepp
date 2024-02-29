#include "game/apple.hpp"


Apple::Apple() {}


void Apple::repos(Grid* grid) {
    std::vector<Cell*> empty_cells;

    for (unsigned char row = CONST::UINT_ZERO; row < CONST::GRID_ROWS; row++) {
        for (unsigned char col = CONST::UINT_ZERO; col < CONST::GRID_COLUMNS; col++) {
            
            Cell* cell = grid->cell_at(Vector(row, col));

            if (cell->type == EMPTY) {
                empty_cells.push_back(cell);
            }
        }
    }
    
    int random_index = GetRandomValue(0, empty_cells.size());
    empty_cells[random_index]->set_state(APPLE);
}