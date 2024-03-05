#pragma once

#include <string>

#include "layout_data.hpp"
#include "color_data.hpp"
#include "config_data.hpp"


namespace PATH {
    const std::string FONT = "resources/fonts/font.ttf";
    const std::string LAYOUT = "resources/data/layout";
    const std::string COLORS = "resources/data/colors";
    const std::string SETTINGS = "resources/data/settings";
    const std::string KEYBINDS = "resources/data/keybinds";
}

namespace CONST {
    constexpr double FLOAT_ZERO = 0.0F;
    constexpr double FLOAT_ONE = 1.0F;
    
    constexpr unsigned int UINT_ZERO = 0U;
    constexpr unsigned int UINT_ONE = 1U;
    constexpr double MS_TO_S = 1.0F / 1000.0F;

    constexpr unsigned int GRID_COLUMNS = 20U;
    constexpr unsigned int GRID_ROWS = 20U;
    constexpr unsigned int CELL_SIZE = 40U;
    constexpr unsigned int CELL_GAP = 3U;

    constexpr unsigned int DELAY_MIN = 50U;
    constexpr unsigned int DELAY_MAX = 200U;
    constexpr unsigned int SPEED_MIN = 1U;
    constexpr unsigned int SPEED_MAX = 10U;
 
    constexpr unsigned int SLIDER_SIZE = 30U;
    constexpr unsigned int SLIDER_RAIL_WIDTH = 15U;

    constexpr unsigned int APPLE_MULTIPLIER = 3U;
    constexpr unsigned int BONUS_MULTIPLIER = 10U;
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

extern LayoutData LAYOUT;
extern ColorData COLORS;