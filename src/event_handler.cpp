#include "event_handler.h"


EventHandler::EventHandler(void) {}


EventHandler::~EventHandler(void) {
    for (Key* key : keyref) {
        delete key;
    }
}

bool EventHandler::check(int keycode, keymode mode) {
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
    keyref.push_back(key);
}


void EventHandler::update(void) {
    for (Key* key : keyref) {
        key->update();
    }
}