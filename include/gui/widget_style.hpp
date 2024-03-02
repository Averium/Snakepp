#pragma once

#include "raylib.hpp"
#include "const.hpp"


typedef struct {

    unsigned char font_size = 42U;
    Color color_1_active = COLORS("GREY0");
    Color color_1_passive = COLORS("GREY0");
    Color color_2_active = COLORS("GREY0");
    Color color_2_passive = COLORS("GREY0");
    Color color_3_active = COLORS("GREY0");
    Color color_3_passive = COLORS("GREY0");

} WidgetStyle;


const WidgetStyle STYLE_LIGHT_42 = { 42U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_LIGHT_32 = { 32U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_DARK_42 =  { 42U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_DARK_32 =  { 32U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_RED_42 =   { 42U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_RED_32 =   { 32U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };

const WidgetStyle STYLE_HEADER =   {
    42U,
    COLORS("BACKGROUND"),
    COLORS("HEADER"),
    COLORS("RED180"),
    COLORS("RED120"),
    COLORS("GREEN120"),
    COLORS("GREEN80")
};
