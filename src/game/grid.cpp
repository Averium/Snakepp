#include <iostream>

#include "const.hpp"
#include "game/grid.hpp"


Grid::Grid(void) {}


Grid::Grid(const Vector position) : Rect(position.x, position.y, GRID_COLUMNS * CELL_SIZE, GRID_COLUMNS * CELL_SIZE) {
    unsigned char col, row;
    
    for (row = UINT_ZERO; row < GRID_ROWS; row++) {
        for (col = UINT_ZERO; col < GRID_COLUMNS; col++) {      
            grid[row][col] = Cell(Vector(col, row), position, EMPTY, UINT_ZERO);
        }
    }
}


Cell* Grid::cell_at(Vector position) {
    return &grid[position.y][position.x];
}


void Grid::update(void) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.update();
        }
    }
}


void Grid::render_background(void) const {
    draw(COLORS("GRID"));
}


void Grid::render_cells(Vector snake_direction) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.render(topleft(), snake_direction);
        }
    }
}