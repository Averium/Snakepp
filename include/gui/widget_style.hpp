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


const WidgetStyle STYLE_LIGHT_42 = { 42U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_LIGHT_32 = { 32U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_DARK_42 =  { 42U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_DARK_32 =  { 32U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_RED_42 =   { 42U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_RED_32 =   { 32U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_HEADER =   { 42U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY40"),  COLORS("GREY20")  };