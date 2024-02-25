#include "text_label.h"
#include "gui.h"
#include "debug.h"


TextLabel::TextLabel() : style(grey_widget) {}


TextLabel::TextLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    const WidgetStyle style,
    Alignment alignment,
    int layer

) : Widget(group, Rect(), alignment, layer), text(text), style(style)
{
    Vector text_dim = Vector(MeasureTextEx(gui->font, text.c_str(), style.font_size, 0.0F));
    width(text_dim.x);
    height(text_dim.y);
    align(position);
}


void TextLabel::draw_text(const char* text, Color color, Vector position) const {
    Vector2 text_pos = (topleft() + position).vector2();
    DrawTextEx(gui->font, text, text_pos, style.font_size, 0.0F, color);
}


void TextLabel::render(void) const {
    draw_text(text.c_str(), style.primary_color_passive);
}

