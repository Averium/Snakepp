#include "text_label.hpp"
#include "gui.hpp"
#include "debug.hpp"


TextLabel::TextLabel() : style(STYLE_LIGHT_42) {}


TextLabel::TextLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    const WidgetStyle style,
    Alignment alignment,
    int layer

) : Widget(group, Rect(), alignment, layer), text(text), style(style)
{
    Vector text_dim = text_dimensions(text.c_str());
    width(text_dim.x);
    height(text_dim.y);
    align(position);
}


Vector TextLabel::text_dimensions(const char* text) const {
    return Vector(MeasureTextEx(gui->font, text, style.font_size, 0.0F));
}


void TextLabel::draw_text(const char* text, Color color, Vector position) const {
    Vector2 text_pos = (topleft() + position).vector2();
    DrawTextEx(gui->font, text, text_pos, style.font_size, 0.0F, color);
}


void TextLabel::render(void) const {
    draw_text(text.c_str(), style.primary_color_passive);
}

