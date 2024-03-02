#pragma once

#include "text_label.hpp"


template <typename DATATYPE>
class DataLabel : public TextLabel {

public:
    DataLabel() : TextLabel() {}

    DataLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        DATATYPE value,
        const WidgetStyle style,
        Alignment alignment = TOPLEFT,
        int layer = 1
    ) : TextLabel(group, position, text + ": ", style, alignment, layer), value(value)
    {

    }


    virtual void set_value(DATATYPE value) {
        this->value = value;
        update_size();    
    }


    virtual std::string value_text(void) const { return std::to_string(value); }


    virtual void update_size(void) {
        Vector text_dim = text_dimensions(text.c_str());
        Vector state_text_dim = text_dimensions(value_text().c_str());

        width(text_dim.x + state_text_dim.x);
        height(text_dim.y > state_text_dim.y ? text_dim.y : state_text_dim.y);
        
        align(anchor);
    }


    virtual void render(void) const {
        Vector text_dim = text_dimensions(text.c_str());

        draw_text(text.c_str(), style.color_2_passive);
        draw_text(value_text().c_str(), style.color_1_passive, Vector(text_dim.x, 0));
    }

private:

    DATATYPE value;
};