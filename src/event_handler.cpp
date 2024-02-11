#include "event_handler.h"


EventHandler::EventHandler(void) {}


bool EventHandler::check(int keycode, keymode mode) {
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


void EventHandler::add_key(int keycode) {
    keymap[keycode] = Key(keycode);
    keyref.push_back(&keymap[keycode]);
}


void EventHandler::update(void) {
    for (Key* key : keyref) {
        key->update();
    }
}