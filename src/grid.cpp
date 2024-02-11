#include <iostream>

#include "const.h"
#include "grid.h"


Grid::Grid(void) {}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
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


void Grid::update(void) {
    Cell* cell;

    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->update();
        }
    }
}