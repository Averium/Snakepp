#include "switch.hpp"


Switch::Switch() {}


Switch::Switch(
    WidgetGroup* group,
    Vector position,
    const std::string& text,
    const WidgetStyle style,
    bool state,
    const std::string& on_text,
    const std::string& off_text,
    Alignment alignment,
    int layer
) :
    DataLabel<bool>(group, position, text + ": ", state, style, alignment, layer),
    on_text(on_text),
    off_text(off_text)    
{
    set_value(value);
}


void Switch::relay(void) { set_value(!value); }


void Switch::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);
    if (is_clicked()) { relay(); }
}