#pragma once

#include <vector>

#include "raylib.h"
#include "const.h"
#include "cell.h"


class Grid{

public:

    Grid(void);
    Grid(Vector position);

    void update(void);
    void render_background(void);
    void render_cells(Vector snake_direction);

    Cell* cell_at(Vector position);

private:
    Cell grid[CONST::GRID_ROWS][CONST::GRID_COLUMNS];
    Vector position;
};