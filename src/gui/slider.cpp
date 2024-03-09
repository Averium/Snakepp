#include "slider.hpp"
#include "raylib.hpp"


Slider::Slider() {}


Slider::Slider(
    WidgetGroup* group,
    Vector position,
    unsigned int length,
    double value,
    WidgetStyle style,
    Alignment alignment,
    int layer
) : 
    Widget(group, Rect(position.x, position.y, length, SLIDER_SIZE), alignment, layer),
    ValueMap(0U, 0U, length, "PIXELS"),
    style(style)
{
    align(position);

    rail.size(this->width(), SLIDER_RAIL_WIDTH);
    rail.midleft(this->midleft());

    slider.centerx(this->left());
    slider.centery(this->centery());

    add_range(left(), right(), "WINDOW");
}


void Slider::set_value(const double normalized_value) {
    this->normalized_value = normalized_value;
}


void Slider::set_value(const unsigned int value, const std::string range_key) {
    this->set(value, range_key);
    slider.centerx(this->get("WINDOW"));
}


void Slider::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (mouse.check(MOUSE_BUTTON_LEFT, PRESS) && is_hovered()) { grabbed = true; }
    if (!mouse.check(MOUSE_BUTTON_LEFT, HOLD)) { grabbed = false; }
    if (is_grabbed()) {
        slider.centerx(clamp_position(mouse.get_position().x));
        double new_value = ((double)(slider.centerx()) - (double)(rail.left())) / (double)(rail.width());
        set_value(new_value);
    }
}


void Slider::render(void) const {
    Color rail_color = (is_grabbed() || is_hovered()) ? style.color_2_active : style.color_2_passive;
    Color slider_color = (is_grabbed() || is_hovered()) ? style.color_1_active : style.color_1_passive;

    rail.draw(rail_color);
    slider.draw(slider_color);
}
