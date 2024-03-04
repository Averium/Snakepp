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
    Color color = hovered ? style.color_1_active : style.color_1_passive;
    draw_text(text.c_str(), color);
}