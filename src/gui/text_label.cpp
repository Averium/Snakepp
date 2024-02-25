#include "text_label.h"
#include "gui.h"
#include "debug.h"


TextLabel::TextLabel() {}


TextLabel::TextLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    unsigned char text_size,
    Vector anchor,
    Align align,
    int layer

) : Widget(group, Rect(position.x, position.y, 0, 0), anchor, align, layer), text(text), text_size(text_size)
{
    Vector2 text_dim = MeasureTextEx(gui->font, text.c_str(), (float)(text_size), 0.0F);
    width((unsigned int)(text_dim.x));
    height((unsigned int)(text_dim.y));
}


void TextLabel::render(void) const {
    DrawTextEx(gui->font, text.c_str(), {(float)(left()), (float)(top())}, (float)(text_size), 0.0F, COLORS::APPLE);
}

