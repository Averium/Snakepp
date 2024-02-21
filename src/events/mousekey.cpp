#include "mousekey.h"


MouseKey::MouseKey(int keycode) : Key::Key(keycode) {}


void MouseKey::update(void) {
    last_pressed = pressed;
    pressed = IsMouseButtonDown(keycode);
}
