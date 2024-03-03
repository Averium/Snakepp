#include "event_handler.hpp"


EventHandler::EventHandler(void) {}


EventHandler::~EventHandler(void) {
    for (std::pair<const int, Key*>& pair : keymap) {
        delete pair.second;
    }
}

bool EventHandler::check(int keycode, keymode mode) {
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


void EventHandler::add_key(int keycode) {
    Key* key = new Key(keycode);
    keymap[keycode] = key;
}


void EventHandler::update(void) {
    for (std::pair<const int, Key*>& pair : keymap) {
        pair.second->update();
    }
}