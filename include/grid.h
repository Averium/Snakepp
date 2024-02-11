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
    void render(void);

    Cell* cell_at(Vector position);

private:
    Cell grid[GRID_ROWS][GRID_COLUMNS];
    Vector position;
};