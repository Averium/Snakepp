#pragma once

#include <vector>

#include "raylib.hpp"
#include "const.hpp"
#include "cell.hpp"


class Grid : public Rect{

public:

    Grid(void);
    Grid(const Vector position);

    void update(void);
    void render_background(void) const;
    void render_cells(const Vector snake_direction);

    Cell* cell_at(const Vector position);

private:
    Cell grid[GRID_ROWS][GRID_COLUMNS];
};