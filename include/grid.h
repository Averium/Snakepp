#pragma once

#include <vector>

#include "raylib.h"
#include "const.h"
#include "cell.h"


class Grid{

public:

    Grid(void);

    void init_grid(void);
    void print(void);
    void render(void);

    Cell grid[GRID_ROWS][GRID_COLUMNS];

private:

};