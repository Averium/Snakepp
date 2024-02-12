#include "mouse_handler.h"


MouseHandler::MouseHandler(void) {}


bool MouseHandler::check(int keycode, keymode mode) {
    Key* key = &keymap[keycode];
    
    switch (mode) {

    case PRESS:
        return key->is_pressed();
    case RELEASE:
        return key->is_released();
    case HOLD:
        return key->is_holded();
    default:
        return false;
    }
}


void MouseHandler::add_key(int keycode) {
    keymap[keycode] = Key(keycode);
    keyref.push_back(&keymap[keycode]);
}


void MouseHandler::update(void) {
    for (Key* key : keyref) {
        key->update();
    }
}