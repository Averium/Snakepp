#pragma once

#include "raylib.h"


#define FPS 60U

#define GRID_COLUMNS 20U
#define GRID_ROWS 20U
#define CELL_SIZE 30U
#define CELL_GAP 1U

#define NON_TRANSPARENT 255U


namespace COLORS {
    const Color BACKGROUND = {50, 220, 0, NON_TRANSPARENT};
    const Color SNAKE = {0, 150, 0, NON_TRANSPARENT};
    const Color APPLE = {200, 0, 0, NON_TRANSPARENT};
}

const unsigned int CELL_SIDE = (CELL_SIZE - CELL_GAP * 2U);