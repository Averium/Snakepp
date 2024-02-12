#include "keyboard_handler.h"


KeyboardHandler::KeyboardHandler(void) {}


bool KeyboardHandler::check(int keycode, keymode mode) {
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


void KeyboardHandler::add_key(int keycode) {
    keymap[keycode] = Key(keycode);
    keyref.push_back(&keymap[keycode]);
}


void KeyboardHandler::update(void) {
    for (Key* key : keyref) {
        key->update();
    }
}