#include "keyboard_handler.hpp"


KeyboardHandler::KeyboardHandler() : EventHandler() {}


KeyboardHandler::KeyboardHandler(ConfigData<unsigned int>* keybinds) : EventHandler(), keybinds(keybinds) {
    for (auto& pair : (*keybinds->all())) {
        add_key(pair.second);
    }
}


bool KeyboardHandler::check(const std::string key, Keymode keymode) {
    const unsigned int keycode = keybinds->operator()(key);
    return EventHandler::check(keycode, keymode);
}