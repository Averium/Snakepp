#include "button.hpp"


Button::Button() {}


Button::Button(
    WidgetGroup* group,
    Vector position,
    std::string text,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) : TextLabel(group, position, text, style, alignment, layer) {}


void Button::render(void) const {
    Color color = focused ? style.primary_color_active : style.primary_color_passive;
    draw_text(text.c_str(), color);
}