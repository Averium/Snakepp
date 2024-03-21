#pragma once

#include <vector>

#include "raylib.hpp"
#include "const.hpp"
#include "cell.hpp"
#include "color_data.hpp"


class Grid : public Rect{

public:

    Grid(void);
    Grid(const Vector position);

    void update(void);
    void render_background(ColorData& colors) const;
    void render_cells(ColorData& colors, const Vector snake_direction, const bool passive = false);

    Cell& cell_at(const Vector position);
    std::vector<Cell*> empty_cells(void);

private:
    Cell grid[GRID_ROWS][GRID_COLUMNS];
};