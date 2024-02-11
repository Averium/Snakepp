#include <iostream>

#include "const.h"
#include "grid.h"


Grid::Grid(void) {

}

void Grid::init_grid(void) {

}


void Grid::print(void) {
    Cell* cell;

    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            cell = &grid[row][col];
            std::cout << cell->type << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::render(void) {
    Cell* cell;

    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->render(row, col);
        }
    }
}