#pragma once

#include <vector>

#include "raylib.h"
#include "const.h"
#include "cell.h"


class Grid{

public:

    Grid(void);

    void print(void);
    void update(void);
    void render(void);

    Cell* cell_at(Vector position);

private:
    Cell grid[GRID_ROWS][GRID_COLUMNS];
};