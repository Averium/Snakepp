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
        Alignment alignment = CENTER,
        int layer = 1
    ) : TextLabel(group, position, text, style, alignment, layer)
    {
        set_value(value);
    }


    virtual void set_value(DATATYPE value) {
        this->value = value;
        value_changed = true;
        update_size();
    }

    virtual DATATYPE get_value(void) const {
        return value;
    }


    virtual std::string value_text(void) const {
        if constexpr(std::is_same_v<DATATYPE, std::string>) {
            return value;
        } else {
            return std::to_string(value);
        }
    }


    virtual void update_size(void) {
        Vector text_dim = text_dimensions(text.c_str());
        Vector state_text_dim = text_dimensions(value_text().c_str());

        if (style.fixed_width > UINT_ZERO) {
            width(style.fixed_width);
        }
        else {
            width(text_dim.x + state_text_dim.x);
        }

        height(text_dim.y > state_text_dim.y ? text_dim.y : state_text_dim.y);
        align();
    }


    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override {
        Widget::events(mouse, keyboard);
        value_changed = false;
    }


    virtual void render(void) const override {
        if (text == "") { return; }
        
        Vector text_dim = text_dimensions(text.c_str());
        Vector data_dim = text_dimensions(value_text().c_str());

        Color primary_color = is_hovered() ? style.color_1_active : style.color_1_passive;
        Color secondary_color = is_hovered() ? style.color_2_active : style.color_2_passive;
        
        Vector text_position = (style.fixed_width > UINT_ZERO) ? Vector(width() - data_dim.x, 0) : Vector(text_dim.x, 0);

        draw_text(text.c_str(), secondary_color);
        draw_text(value_text().c_str(), primary_color, text_position);
    }

protected:
    bool value_changed = false;

    DATATYPE value;
};