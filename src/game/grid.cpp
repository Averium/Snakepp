#include <iostream>

#include "const.h"
#include "game/grid.h"


Grid::Grid(void) {}


Grid::Grid(Vector position) {
    this->position = position;

    for (unsigned char row = CONST::UINT_ZERO; row < CONST::GRID_ROWS; row++) {
        for (unsigned char col = CONST::UINT_ZERO; col < CONST::GRID_COLUMNS; col++) {      
            grid[row][col] = Cell(Vector(col, row), EMPTY, CONST::UINT_ZERO);
        }
    }
}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
}


void Grid::update(void) {
    Cell* cell;

    for (unsigned char row = CONST::UINT_ZERO; row < CONST::GRID_ROWS; row++) {
        for (unsigned char col = CONST::UINT_ZERO; col < CONST::GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->update();
        }
    }
}


void Grid::render(Vector snake_direction) {
    Cell* cell;

    DrawRectangle(position.x, position.y, CONST::GRID_COLUMNS * CONST::CELL_SIZE, CONST::GRID_ROWS * CONST::CELL_SIZE, COLORS::GRID);

    for (unsigned char row = CONST::UINT_ZERO; row < CONST::GRID_ROWS; row++) {
        for (unsigned char col = CONST::UINT_ZERO; col < CONST::GRID_COLUMNS; col++) {
            
            cell = &grid[row][col];
            cell->render(position, snake_direction);
        }
    }
}