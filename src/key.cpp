#include "key.h"
#include "debug.h"


Key::Key(void) {
    int keycode = CONST::UINT_ZERO;
}


Key::Key(int keycode) {
    this->keycode = keycode;
}


void Key::update(void) {
    last_pressed = pressed;
    pressed = IsKeyDown(keycode);
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

