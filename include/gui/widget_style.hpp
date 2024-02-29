#pragma once

#include "raylib.hpp"
#include "const.hpp"


typedef struct {

    unsigned char font_size;
    Color primary_color_active;
    Color primary_color_passive;
    Color secondary_color_active;
    Color secondary_color_passive;

} WidgetStyle;


const WidgetStyle grey_widget = {
    42U,
    COLORS::GREY140,
    COLORS::GREY100,
    COLORS::GREY140,
    COLORS::GREY100,
};


const WidgetStyle grey_widget_small = {
    32U,
    COLORS::GREY140,
    COLORS::GREY100,
    COLORS::GREY140,
    COLORS::GREY100,
};


const WidgetStyle red_widget = {
    42U,
    COLORS::RED180,
    COLORS::RED120,
    COLORS::GREY140,
    COLORS::GREY100,
};