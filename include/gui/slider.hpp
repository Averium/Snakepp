#pragma once

#include <algorithm>

#include "widget.hpp"
#include "widget_style.hpp"


class Slider : public Widget {

public:
    Slider();
    Slider(WidgetGroup* group, Vector position, unsigned int length, WidgetStyle style, Alignment alignment = TOPLEFT, int layer = 1);

    inline int clamp_position(int position) const { return std::min(std::max(position, left()), right()); }

    template <typename TYPE>
    TYPE map_value(TYPE min, TYPE max) {
        float normalized = (float)(slider.centerx() - rail.left()) / (float)(rail.width());
        return (TYPE)(normalized * (max - min) + min);
    }

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