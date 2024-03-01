#pragma once

#include <string>

#include "raylib.hpp"
#include "rectangle.hpp"

namespace PATH {
    constexpr char FONT[] = "resources/fonts/font.ttf";
    const std::string LAYOUT = "resources/data/layout";
}

namespace CONST {
    constexpr unsigned int UINT_ZERO = 0U;
    constexpr unsigned int UINT_ONE = 1U;
    constexpr float FLOAT_ZERO = 0.0F;
    constexpr unsigned int FPS = 60U;
    constexpr unsigned int GRID_COLUMNS = 20U;
    constexpr unsigned int GRID_ROWS = 20U;
    constexpr unsigned int CELL_SIZE = 40U;
    constexpr unsigned int CELL_GAP = 1U;
    constexpr unsigned int NON_TRANSPARENT = 255U;

    
    constexpr float GAME_PERIOD = 0.1F;
    constexpr unsigned int STARTING_LENGTH = 3U;
    constexpr char HEADER_TEXT[] = "Click here to move window";
    constexpr char HEADER_TEXT_SIZE = 40U;
}

namespace COLORS {
    const Color GREY20 = {20, 20, 20, CONST::NON_TRANSPARENT};
    const Color GREY30 = {30, 30, 30, CONST::NON_TRANSPARENT};
    const Color GREY40 = {40, 40, 40, CONST::NON_TRANSPARENT};
    const Color GREY100 = {100, 100, 100, CONST::NON_TRANSPARENT};
    const Color GREY140 = {140, 140, 140, CONST::NON_TRANSPARENT};

    const Color RED120 = {120, 0, 0, CONST::NON_TRANSPARENT};
    const Color RED180 = {180, 0, 0, CONST::NON_TRANSPARENT};
    
    const Color BACKGROUND = GREY20;
    const Color GRID = GREY40;
    const Color SNAKE = GREY20;
    const Color PATTERN = GREY40;
    const Color APPLE = GREY20;
    const Color HEADER = GREY20;
    const Color HEADER_TEXT = GREY40;
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

const unsigned int CELL_SIDE = (CONST::CELL_SIZE - CONST::CELL_GAP * 2U);
const Vector START_POS = Vector(5U, 1U);
