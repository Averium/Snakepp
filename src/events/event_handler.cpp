#include "event_handler.hpp"


EventHandler::EventHandler(void) {}


bool EventHandler::check(const unsigned int keycode, const Keymode mode) {
    if (!keymap.contains(keycode)) {
        return false;
    }

    Key* key = keymap[keycode];
    
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


void EventHandler::add_key(const unsigned int keycode) {
    Key* key = new Key(keycode);
    keymap[keycode] = key;
}


void EventHandler::update(void) {
    for (const auto& pair : keymap) {
        pair.second->update();
    }
}