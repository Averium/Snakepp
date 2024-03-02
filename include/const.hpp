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
}

namespace CONST {
    constexpr float FLOAT_ZERO = 0.0F;
    constexpr unsigned int UINT_ZERO = 0U;
    constexpr unsigned int UINT_ONE = 1U;

    constexpr unsigned int GRID_COLUMNS = 20U;
    constexpr unsigned int GRID_ROWS = 20U;
}

namespace DIRECTION {
    const Vector UP    = Vector( 0, -1);
    const Vector DOWN  = Vector( 0,  1);
    const Vector LEFT  = Vector(-1,  0);
    const Vector RIGHT = Vector( 1,  0);
}

extern ConfigData<int> SETTINGS;
extern LayoutData LAYOUT;
extern ColorData COLORS;