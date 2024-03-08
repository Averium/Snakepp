#include "mouse_handler.hpp"


MouseHandler::MouseHandler(void) : EventHandler::EventHandler() {
    add_key(MOUSE_BUTTON_LEFT);
    add_key(MOUSE_BUTTON_MIDDLE);
    add_key(MOUSE_BUTTON_RIGHT);
}


void MouseHandler::add_key(const unsigned int keycode) {
    Key* mouse_key = new MouseKey(keycode);
    keymap[keycode] = mouse_key;
}


void MouseHandler::update(void) {

    for (const auto& pair : keymap) {
        pair.second->update();
    }

    last_position = position;
    position = Vector(GetMousePosition());

    if (!check(MOUSE_BUTTON_LEFT, HOLD)) {
        anchor = position;
    }
    drag = position - anchor;
    
}
