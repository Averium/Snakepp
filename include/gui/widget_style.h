#pragma once

#include "raylib.h"
#include "const.h"


typedef struct {

    unsigned char font_size = 42U;

    Color text_color_active = COLORS::GREY50;
    Color text_color_passive = COLORS::GREY40;
    Color primary_color_active = COLORS::GREY50;
    Color primary_color_passive = COLORS::GREY40;
    Color secondary_color_active = COLORS::RED180;
    Color secondary_color_passive = COLORS::RED120;

} WidgetStyle;