#include <iostream>

#include "const.h"
#include "grid.h"


Grid::Grid(void) {}


Grid::Grid(Vector position) {
    this->position = position;

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {      
            grid[row][col] = Cell(Vector(col, row), EMPTY, UINT_ZERO);
        }
    }
}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
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


void Grid::render(Vector snake_direction) {
    Cell* cell;

    DrawRectangle(position.x, position.y, GRID_COLUMNS * CELL_SIZE, GRID_ROWS * CELL_SIZE, COLORS::GRID);

    for (unsigned char row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (unsigned char col = UINT_ZERO; col < GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->render(position, snake_direction);
        }
    }
}