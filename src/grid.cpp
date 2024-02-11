#include <iostream>

#include "const.h"
#include "grid.h"


Grid::Grid(void) {}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
}


void Grid::render(void) {
    Cell* cell;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->render(row, col);
        }
    }
}


void Grid::update(void) {
    Cell* cell;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->update();
        }
    }
}