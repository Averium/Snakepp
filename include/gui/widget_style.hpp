#pragma once

#include "raylib.hpp"
#include "const.hpp"


typedef struct {

    unsigned int font_size = 42U;
    unsigned int fixed_width = CONST::UINT_ZERO;
    Color color_1_active = COLORS("GREY0");
    Color color_1_passive = COLORS("GREY0");
    Color color_2_active = COLORS("GREY0");
    Color color_2_passive = COLORS("GREY0");
    Color color_3_active = COLORS("GREY0");
    Color color_3_passive = COLORS("GREY0");

} WidgetStyle;


const WidgetStyle STYLE_DARK_72 =  { 72U, 0U, COLORS("GREY80"), COLORS("GREY60"), COLORS("GREY80"), COLORS("GREY60") };
const WidgetStyle STYLE_LIGHT_42 = { 42U, 0U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_LIGHT_32 = { 32U, 0U, COLORS("GREY140"), COLORS("GREY100"), COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_DARK_42 =  { 42U, 0U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_DARK_32 =  { 32U, 0U, COLORS("GREY80"),  COLORS("GREY60"),  COLORS("GREY80"),  COLORS("GREY60")  };
const WidgetStyle STYLE_RED_42 =   { 42U, 0U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_RED_32 =   { 32U, 0U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_GREEN_42 = { 42U, 0U, COLORS("GREEN120"),  COLORS("GREEN80"),  COLORS("GREY140"), COLORS("GREY100") };
const WidgetStyle STYLE_GREEN_32 = { 32U, 0U, COLORS("GREEN120"),  COLORS("GREEN80"),  COLORS("GREY140"), COLORS("GREY100") };

const WidgetStyle STYLE_RED_STATIC_42 =   { 42U, 0U, COLORS("RED120"),  COLORS("RED120"),  COLORS("GREY100"), COLORS("GREY100") };

const WidgetStyle STYLE_SCORE_LABEL = { 42U, 200U, COLORS("RED120"),  COLORS("RED120"),  COLORS("GREY100"), COLORS("GREY100") };
const WidgetStyle STYLE_STAT_LABEL =  { 42U, 200U, COLORS("BLUE140"), COLORS("BLUE140"), COLORS("GREY100"), COLORS("GREY100") };
const WidgetStyle STYLE_KEYBIND_LABEL = { 42U, 350U, COLORS("RED180"),  COLORS("RED120"),  COLORS("GREY140"), COLORS("GREY100") };

const WidgetStyle STYLE_HEADER = {
    42U,
    0U,
    COLORS("BACKGROUND"),
    COLORS("HEADER"),
    COLORS("RED180"),
    COLORS("RED120"),
    COLORS("GREEN120"),
    COLORS("GREEN80")
};
