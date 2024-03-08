#include "keybind_label.hpp"


KeybindLabel::KeybindLabel() {}


KeybindLabel::KeybindLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    std::string keyname,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) :
    DataLabel<std::string>(group, position, text, keyname, style, alignment, layer)
{}


void KeybindLabel::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (is_focused()) {
        if (mouse.check(MOUSE_BUTTON_LEFT, PRESS)) {
            gui->release();
        }

        unsigned int keycode = keyboard.wait_for_key();

        if (keycode != KEY_NULL) {
            keyboard.configure_key(this->text, keycode);
            set_value(keyboard.decode_key(keycode));
            gui->release();
        }

    }
    else {
        if (is_clicked()) { gui->focus(this); }
    }
}


std::string KeybindLabel::value_text(void) const {
    return is_focused() ? placeholder : value;
}


const std::string KeybindLabel::placeholder = "Press a key";
