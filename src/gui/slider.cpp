#include "slider.hpp"
#include "raylib.hpp"


Slider::Slider() {}


Slider::Slider(
    WidgetGroup* group,
    Vector position,
    unsigned int length,
    WidgetStyle style,
    Alignment alignment,
    int layer
) : Widget(group, Rect(position.x, position.y, length, this->slider_size), alignment, layer), style(style)
{
    align(position);

    rail.size(this->width(), this->rail_width);
    rail.midleft(this->midleft());

    slider.centerx(this->left());
    slider.centery(this->centery());
}


void Slider::events(MouseHandler& mouse, EventHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (mouse.check(MOUSE_BUTTON_LEFT, PRESS) && focused) { grabbed = true; }
    if (!mouse.check(MOUSE_BUTTON_LEFT, HOLD)) { grabbed = false; }
    if (grabbed) { slider.centerx(clamp_position(mouse.get_position().x)); }
}


void Slider::render(void) const {
    Color rail_color = (grabbed || focused) ? style.color_2_passive : style.color_2_passive;
    Color slider_color = (grabbed || focused) ? style.color_1_active : style.color_1_passive;

    DrawRectangle(rail.left(), rail.top(), rail.width(), rail.height(), rail_color);
    DrawRectangle(slider.left(), slider.top(), slider.width(), slider.height(), slider_color);
}
