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


Cell& Grid::cell_at(const Vector position) {
    return grid[position.y][position.x];
}


std::vector<Cell*> Grid::empty_cells(void) {
    std::vector<Cell*> cells;

    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell.type == EMPTY) { cells.push_back(&cell); }
        }
    }

    return cells;
}


void Grid::update(void) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.update();
        }
    }
}


void Grid::render_background(void) const {
    draw(COLORS("GREY1"));
}


void Grid::render_cells(const Vector snake_direction, const bool passive) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.render(topleft(), snake_direction);
        }
    }

    if (passive) { draw(COLORS("SHADE")); }
}