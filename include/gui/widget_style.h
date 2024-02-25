#pragma once

#include "raylib.h"
#include "const.h"


typedef struct {

    unsigned char font_size;
    Color primary_color_active;
    Color primary_color_passive;
    Color secondary_color_active;
    Color secondary_color_passive;

} WidgetStyle;


const WidgetStyle grey_widget = {
    42U,
    COLORS::GREY50,
    COLORS::GREY30,
    COLORS::GREY50,
    COLORS::GREY30,
};


const WidgetStyle red_widget = {
    42U,
    COLORS::RED180,
    COLORS::RED120,
    COLORS::GREY50,
    COLORS::GREY30,
};