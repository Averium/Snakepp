#pragma once

#include "raylib.h"
#include "integer_vector.h"
#include "rectangle.h"


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
    const Color BACKGROUND = {20, 20, 20, NON_TRANSPARENT};
    const Color GRID = {60, 60, 60, NON_TRANSPARENT};
    const Color SNAKE = {20, 20, 20, NON_TRANSPARENT};
    const Color PATTERN = {40, 40, 40, NON_TRANSPARENT};
    const Color APPLE = {20, 20, 20, NON_TRANSPARENT};
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

namespace LAYOUT {
    const Vector WINDOW = Vector(CELL_SIZE * (GRID_COLUMNS + 6), CELL_SIZE * (GRID_ROWS + 3));
    const Vector GRID = Vector(CELL_SIZE, CELL_SIZE * 2);
    const Rect HEADER = Rect(0, CELL_SIZE * (GRID_ROWS + 2), LAYOUT::WINDOW.x, CELL_SIZE);
}


const unsigned int CELL_SIDE = (CELL_SIZE - CELL_GAP * 2U);
const Vector START_POS = Vector(5U, 1U);