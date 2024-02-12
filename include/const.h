#pragma once

#include "raylib.h"
#include "rectangle.h"

namespace CONST {
    constexpr unsigned int UINT_ZERO = 0U;
    constexpr unsigned int UINT_ONE = 1U;
    constexpr float FLOAT_ZERO = 0.0F;
    constexpr unsigned int FPS = 60U;
    constexpr float GAME_PERIOD = 0.1F;
    constexpr unsigned int STARTING_LENGTH = 3U;
    constexpr unsigned int GRID_COLUMNS = 20U;
    constexpr unsigned int GRID_ROWS = 20U;
    constexpr unsigned int CELL_SIZE = 40U;
    constexpr unsigned int CELL_GAP = 1U;
    constexpr unsigned int NON_TRANSPARENT = 255U;
    constexpr char HEADER_TEXT[] = "Click here to move window";
    constexpr char HEADER_TEXT_SIZE = 40U;
}

namespace PATH {
    constexpr char FONT[] = "resources/fonts/font.ttf";
}

namespace COLORS {
    const Color BACKGROUND = {20, 20, 20, CONST::NON_TRANSPARENT};
    const Color GRID = {40, 40, 40, CONST::NON_TRANSPARENT};
    const Color SNAKE = {20, 20, 20, CONST::NON_TRANSPARENT};
    const Color PATTERN = {40, 40, 40, CONST::NON_TRANSPARENT};
    const Color APPLE = {20, 20, 20, CONST::NON_TRANSPARENT};
    const Color HEADER = {20, 20, 20, CONST::NON_TRANSPARENT};
    const Color HEADER_TEXT = {40, 40, 40, CONST::NON_TRANSPARENT};
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

namespace LAYOUT {
    const Vector WINDOW = Vector(CONST::CELL_SIZE * (CONST::GRID_COLUMNS + 6), CONST::CELL_SIZE * (CONST::GRID_ROWS + 2));
    const Vector GRID = Vector(CONST::CELL_SIZE, CONST::CELL_SIZE);
    inline Rect HEADER = Rect(0, 0, (CONST::CELL_SIZE * (CONST::GRID_COLUMNS + 6)), CONST::CELL_SIZE);
}

const unsigned int CELL_SIDE = (CONST::CELL_SIZE - CONST::CELL_GAP * 2U);
const Vector START_POS = Vector(5U, 1U);