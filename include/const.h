#pragma once

#include "raylib.h"
#include "intvector.h"


#define FPS 60U
#define GAME_PERIOD 0.5F

#define STARTING_LENGTH 3U

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

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

const unsigned int CELL_SIDE = (CELL_SIZE - CELL_GAP * 2U);