#include "key.hpp"


Key::Key(void) {
    int keycode = UINT_ZERO;
}


Key::Key(int keycode) {
    this->keycode = keycode;
}


void Key::update(void) {
    last_pressed = pressed;
    pressed = IsKeyDown(keycode);
}


void Key::set_keycode(int new_keycode) {
    keycode = new_keycode;
}


bool Key::is_pressed(void) const {
    return (pressed && !last_pressed);
}


bool Key::is_released(void) const {
    return (!pressed && last_pressed);
}


bool Key::is_holded(void) const {
    return pressed;
}

