#pragma once

#include "raylib.h"
#include "integer_vector.h"


#define UINT_ZERO 0U
#define UINT_ONE 1U

#define FLOAT_ZERO 0.0F

#define FPS 60U
#define GAME_PERIOD 0.1F

#define STARTING_LENGTH 3U

#define GRID_COLUMNS 20U
#define GRID_ROWS 20U
#define CELL_SIZE 40U
#define CELL_GAP 1U

#define TITLE "SNAKE"

#define NON_TRANSPARENT 255U


namespace COLORS {
    const Color BACKGROUND = {30, 30, 30, NON_TRANSPARENT};
    const Color GRID = {50, 200, 0, NON_TRANSPARENT};
    const Color SNAKE = {0, 150, 0, NON_TRANSPARENT};
    const Color APPLE = {200, 0, 0, NON_TRANSPARENT};
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

namespace LAYOUT {
    const Vector WINDOW = Vector(CELL_SIZE * (GRID_COLUMNS + 2), CELL_SIZE * (GRID_ROWS + 2));
    const Vector GRID = Vector(CELL_SIZE, CELL_SIZE);
}


const unsigned int CELL_SIDE = (CELL_SIZE - CELL_GAP * 2U);