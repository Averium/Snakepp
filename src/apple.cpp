#include "apple.h"


Apple::Apple() {}


void Apple::repos(Grid* grid) {
    std::vector<Cell*> empty_cells;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            Cell* cell = grid->cell_at(Vector(row, col));

            if (cell->type == EMPTY) {
                empty_cells.push_back(cell);
            }
        }
    }
    
    int random_index = GetRandomValue(0, empty_cells.size());
    empty_cells[random_index]->set_state(APPLE);
}