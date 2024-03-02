#include "switch.hpp"


Switch::Switch() {}


Switch::Switch(
    WidgetGroup* group,
    Vector position,
    std::string text,
    const WidgetStyle style,
    bool state,
    Alignment alignment,
    int layer
) : TextLabel(group, position, text + ": ", style, alignment, layer)
{
    relay(state);
}


void Switch::relay(void) {
    state = !state;
    update_size();
}


void Switch::relay(bool state) {
    this->state = state;
    update_size();
}


void Switch::events(MouseHandler& mouse, EventHandler& keyboard) {
    Widget::events(mouse, keyboard);
    if (clicked) { relay(); }
}


void Switch::render(void) const {
    Vector text_dim = text_dimensions(text.c_str());

    Color primary_color = focused ? style.color_1_active : style.color_1_passive;
    Color secondary_color = focused ? style.color_2_active : style.color_2_passive;
    
    draw_text(text.c_str(), secondary_color);
    draw_text(state_text().c_str(), primary_color, Vector(text_dim.x, 0));
}


void Switch::update_size(void) {
    Vector text_dim = text_dimensions(text.c_str());
    Vector state_text_dim = text_dimensions(state_text().c_str());

    width(text_dim.x + state_text_dim.x);
    height(text_dim.y > state_text_dim.y ? text_dim.y : state_text_dim.y);
    
    align(anchor);
}