#pragma once

#include <string>

#include "layout_data.hpp"
#include "color_data.hpp"
#include "config_data.hpp"


#define FLOAT_ZERO 0.0F
#define FLOAT_ONE 1.0F

#define UINT_ZERO 0U
#define UINT_ONE 1U
#define MS_TO_S 0.001F

#define GRID_COLUMNS 20U
#define GRID_ROWS 20U
#define CELL_SIZE 40U
#define CELL_GAP 3U

#define DELAY_MIN 50U
#define DELAY_MAX 200U
#define SPEED_MIN 1U
#define SPEED_MAX 10U

#define SLIDER_SIZE 30U
#define SLIDER_RAIL_WIDTH 15U

#define APPLE_MULTIPLIER 3U
#define BONUS_MULTIPLIER 10U
#define STORED_HIGHSCORES 5U

#define CURSOR_FLASH_PERIOD 0.4F
#define BONUS_FLASH_PERIOD 0.2F
#define BONUS_ALIVE_CYCLES 40U

#define ROLL_MAX 1000U
#define ROLL_BONUS_CHANCE 100U


namespace PATH {
    const std::string FONT = "resources/fonts/font.ttf";
    const std::string LAYOUT = "resources/data/layout";
    const std::string COLORS = "resources/data/colors";
    const std::string SETTINGS = "resources/data/settings";
    const std::string KEYBINDS = "resources/data/keybinds";
    const std::string HIGHSCORES = "resources/data/highscores";
}


namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

extern LayoutData LAYOUT;
extern ColorData COLORS;