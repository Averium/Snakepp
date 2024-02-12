#include "mouse_handler.h"
#include "event_handler.h"


MouseHandler::MouseHandler(void) : EventHandler::EventHandler() {}


void MouseHandler::add_key(int keycode) {
    Key* mouse_key = new MouseKey(keycode);
    keymap[keycode] = mouse_key;
    keyref.push_back(mouse_key);
}


void MouseHandler::update(void) {
    for (Key* key : keyref) {
        key->update();
    }
}