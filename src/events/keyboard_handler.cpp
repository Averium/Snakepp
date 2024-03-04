#include "keyboard_handler.hpp"
#include "debug.hpp"


KeyboardHandler::KeyboardHandler() : EventHandler() {}


KeyboardHandler::KeyboardHandler(ConfigData<unsigned int>* keybinds) : EventHandler(), keybinds(keybinds) {
    update_keys();
}


void KeyboardHandler::update_keys(void) {
    keymap.clear();
    for (auto& pair : (*keybinds->all())) {
        add_key(pair.second);
    }
}


void KeyboardHandler::save_keybinds(void) {
    keybinds->save();
}


void KeyboardHandler::configure_key(const std::string keyname, unsigned int keycode) {
    (*keybinds)(keyname, keycode);
    update_keys();
}


bool KeyboardHandler::check(const std::string keyname, Keymode keymode) {
    const unsigned int keycode = (*keybinds)(keyname);
    return EventHandler::check(keycode, keymode);
}


unsigned int KeyboardHandler::wait_for_key(void) {
    for (unsigned int keycode = KEY_ZERO; keycode < KEY_Z; keycode++) {
        if (IsKeyDown(keycode)) { return keycode; }
    }

    for (unsigned int keycode = KEY_ESCAPE; keycode < KEY_KP_9; keycode++) {
        if (IsKeyDown(keycode)) { return keycode; }
    }

    if (IsKeyDown(KEY_SPACE)) { return KEY_SPACE; }

    return KEY_NULL;
}