#pragma once

#include <algorithm>

#include "widget.hpp"
#include "widget_style.hpp"
#include "value_map.hpp"


class Slider : public Widget, public ValueMap {

public:
    Slider();
    Slider(WidgetGroup* group, Vector position, unsigned int length, double value, WidgetStyle style, Alignment alignment = TOPLEFT, int layer = 1);

    inline int clamp_position(int position) const { return std::min(std::max(position, left()), right()); }
    inline double get_value(void) const { return normalized_value; }
    inline unsigned int get_value(const std::string range_key) { return this->get(range_key); }

    void set_value(const double new_value);
    void set_value(const unsigned int new_value, const std::string range_key);

    void events(MouseHandler& mouse, EventHandler& keyboard) override;
    void render(void) const override;

private:
    static const unsigned int slider_size = 30U;
    static const unsigned int rail_width = 15U;

    bool grabbed;

    WidgetStyle style;

    Rect slider = Rect(0, 0, slider_size, slider_size);
    Rect rail = Rect();
};