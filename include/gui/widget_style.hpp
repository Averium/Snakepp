#pragma once

#include "raylib.hpp"
#include "const.hpp"


#define SIZE_1 32U
#define SIZE_2 42U
#define SIZE_3 72U


struct WidgetStyle {

    WidgetStyle(
        unsigned int font_size      = SIZE_2,
        unsigned int fixed_width    = UINT_ZERO,
        std::string color_1_active  = "BLACK",
        std::string color_1_passive = "BLACK",
        std::string color_2_active  = "BLACK",
        std::string color_2_passive = "BLACK",
        std::string color_3_active  = "BLACK",
        std::string color_3_passive = "BLACK"
    ) :
        font_size      ( font_size              ),
        fixed_width    ( fixed_width            ),
        color_1_active ( COLORS(color_1_active )),
        color_1_passive( COLORS(color_1_passive)),
        color_2_active ( COLORS(color_2_active )),
        color_2_passive( COLORS(color_2_passive)),
        color_3_active ( COLORS(color_3_active )),
        color_3_passive( COLORS(color_3_passive))
    {}

    unsigned int font_size = SIZE_2;
    unsigned int fixed_width = UINT_ZERO;

    Color color_1_active =  COLORS("GREY0");
    Color color_1_passive = COLORS("GREY0");
    Color color_2_active =  COLORS("GREY0");
    Color color_2_passive = COLORS("GREY0");
    Color color_3_active =  COLORS("GREY0");
    Color color_3_passive = COLORS("GREY0");

};


const WidgetStyle STYLE_DARK_1  ( SIZE_1, UINT_ZERO, "GREY4",  "GREY3",  "GREY3", "GREY2"  );    
const WidgetStyle STYLE_DARK_2  ( SIZE_2, UINT_ZERO, "GREY4",  "GREY3",  "GREY3", "GREY2"  );    
const WidgetStyle STYLE_DARK_3  ( SIZE_3, UINT_ZERO, "GREY4",  "GREY3",  "GREY3", "GREY2"  );       

const WidgetStyle STYLE_LIGHT_1 ( SIZE_1, UINT_ZERO, "GREY6",  "GREY5",  "GREY5", "GREY4"  );   
const WidgetStyle STYLE_LIGHT_2 ( SIZE_2, UINT_ZERO, "GREY6",  "GREY5",  "GREY5", "GREY4"  );   
const WidgetStyle STYLE_LIGHT_3 ( SIZE_3, UINT_ZERO, "GREY6",  "GREY5",  "GREY5", "GREY4"  );   

const WidgetStyle STYLE_RED_1   ( SIZE_1, UINT_ZERO, "RED2",   "RED1",   "GREY5", "GREY4" );   
const WidgetStyle STYLE_RED_2   ( SIZE_2, UINT_ZERO, "RED2",   "RED1",   "GREY5", "GREY4" );   
const WidgetStyle STYLE_RED_3   ( SIZE_3, UINT_ZERO, "RED2",   "RED1",   "GREY5", "GREY4" );   

const WidgetStyle STYLE_GREEN_1 ( SIZE_1, UINT_ZERO, "GREEN3", "GREEN2", "GREY5", "GREY4" );
const WidgetStyle STYLE_GREEN_2 ( SIZE_2, UINT_ZERO, "GREEN3", "GREEN2", "GREY5", "GREY4" );
const WidgetStyle STYLE_GREEN_3 ( SIZE_3, UINT_ZERO, "GREEN3", "GREEN2", "GREY5", "GREY4" );

const WidgetStyle STYLE_RED_2_S   ( SIZE_2, UINT_ZERO, "RED1",  "RED1",  "GREY4", "GREY4" );
const WidgetStyle STYLE_LIGHT_2_S ( SIZE_2, UINT_ZERO, "GREY6", "GREY6", "GREY4", "GREY4" );



const WidgetStyle STYLE_SCORE_LABEL     ( SIZE_2, 200U, "GREY6", "GREY6", "GREY4", "GREY4" );
const WidgetStyle STYLE_STAT_LABEL_RED  ( SIZE_2, 200U, "RED2",  "RED2",  "GREY4", "GREY4" );
const WidgetStyle STYLE_STAT_LABEL_BLUE ( SIZE_2, 200U, "BLUE2", "BLUE2", "GREY4", "GREY4" );
const WidgetStyle STYLE_KEYBIND_LABEL   ( SIZE_2, 350U, "RED2",  "RED1",  "GREY6", "GREY4" );
const WidgetStyle STYLE_HIGHSCORE_INPUT ( SIZE_2, 500U, "RED2",  "RED1",  "GREY6", "GREY4" );
const WidgetStyle STYLE_HIGHSCORE_LABEL ( SIZE_2, 400U, "RED1",  "RED1",  "GREY4", "GREY4" );
const WidgetStyle STYLE_HEADER          ( SIZE_2, UINT_ZERO,   "GREY2",  "GREY1",  "RED2",  "RED1", "GREEN3", "GREEN2" );
