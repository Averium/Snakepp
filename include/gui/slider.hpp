#pragma once

#include <algorithm>

#include "widget.hpp"
#include "widget_style.hpp"
#include "value_map.hpp"


class Slider : public Widget, public ValueMap {

public:
    Slider();
    Slider(
        WidgetGroup* group,
        Vector position,
        unsigned int length,
        double value,
        WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = UINT_ONE
    );

    inline bool is_grabbed(void) const { return grabbed; }
    inline int clamp_position(int position) const { return std::min(std::max(position, left()), right()); }
    inline double get_value(void) const { return normalized_value; }
    inline unsigned int get_value(const std::string range_key) { return this->get(range_key); }

    void set_value(const double new_value);
    void set_value(const unsigned int new_value, const std::string range_key);

    void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    void render(void) const override;

private:
    bool grabbed = false;

    WidgetStyle style;

    Rect slider = Rect(UINT_ZERO, UINT_ZERO, SLIDER_SIZE, SLIDER_SIZE);
    Rect rail = Rect();
};