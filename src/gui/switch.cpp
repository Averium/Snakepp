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
) : DataLabel<bool>(group, position, text + ": ", state, style, alignment, layer) {
    set_value(value);
}


void Switch::relay(void) { set_value(!value); }


void Switch::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);
    if (is_clicked()) { relay(); }
}