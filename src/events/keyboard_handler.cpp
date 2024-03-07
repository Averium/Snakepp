#include "keyboard_handler.hpp"


KeyboardHandler::KeyboardHandler() : EventHandler() {}


KeyboardHandler::KeyboardHandler(ConfigData<unsigned int>* keybinds) : EventHandler(), keybinds(keybinds) {
    update_keys();
    
    for (const auto& pair : NUMBERMAP) { KEYMAP.insert(pair); }
    for (const auto& pair : LETTERMAP) { KEYMAP.insert(pair); }
    for (const auto& pair : MODMAP) { KEYMAP.insert(pair); }
}


void KeyboardHandler::update_keys(void) {
    
    for (const auto& pair : keymap) { delete pair.second; };
    keymap.clear();

    for (const auto& pair : (*keybinds->all())) {
        add_key(pair.second);
    }
}


void KeyboardHandler::save_keybinds(void) const {
    keybinds->save();
}


void KeyboardHandler::configure_key(const std::string keyname, const unsigned int keycode) {
    (*keybinds)(keyname, keycode);
    update_keys();
}


bool KeyboardHandler::check(const std::string keyname, const Keymode keymode) {
    return EventHandler::check((*keybinds)(keyname), keymode);
}


bool KeyboardHandler::shift(void) const {
    return IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
}


bool KeyboardHandler::control(void) const {
    return IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
}


bool KeyboardHandler::alt(void) const {
    return IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);
}


unsigned int KeyboardHandler::wait_for_key(void) const {
    for (unsigned int keycode = KEY_ZERO; keycode < KEY_Z; keycode++) {
        if (IsKeyPressed(keycode)) { return keycode; }
    }

    for (unsigned int keycode = KEY_ESCAPE; keycode < KEY_KP_9; keycode++) {
        if (IsKeyPressed(keycode)) { return keycode; }
    }

    if (IsKeyPressed(KEY_SPACE)) { return KEY_SPACE; }

    return KEY_NULL;
}


std::string KeyboardHandler::decode(
    std::unordered_map<unsigned int, std::string>& map,
    const unsigned int keycode
) const {
    if (map.contains(keycode)) {
        return map[keycode];
    }
    else {
        return "NULL";
    }
}


std::unordered_map<unsigned int, std::string> KeyboardHandler::KEYMAP = {
    {KEY_NULL, "NULL"},
    {KEY_APOSTROPHE, "'"},
    {KEY_COMMA, ","},
    {KEY_MINUS, "-"},
    {KEY_PERIOD, "."},
    {KEY_SLASH, "/"},
    {KEY_SEMICOLON, ";"},
    {KEY_EQUAL, "="},
    {KEY_LEFT_BRACKET, "["},
    {KEY_BACKSLASH, "\\"},
    {KEY_RIGHT_BRACKET, "]"},
    {KEY_GRAVE, "Grave"},
    {KEY_SPACE, "Space"},
    {KEY_ESCAPE, "Escape"},
    {KEY_ENTER, "Enter"},
    {KEY_TAB, "Tab"},
    {KEY_BACKSPACE, "Backspace"},
    {KEY_INSERT, "Insert"},
    {KEY_DELETE, "Delete"},
    {KEY_RIGHT, "Right"},
    {KEY_LEFT, "Left"},
    {KEY_DOWN, "Down"},
    {KEY_UP, "Up"},
    {KEY_PAGE_UP, "Page up"},
    {KEY_PAGE_DOWN, "Page down"},
    {KEY_HOME, "Home"},
    {KEY_END, "End"},
    {KEY_CAPS_LOCK, "Caps lock"},
    {KEY_SCROLL_LOCK, "Scroll lock"},
    {KEY_NUM_LOCK, "Num lock"},
    {KEY_PRINT_SCREEN, "Print screen"},
    {KEY_PAUSE, "Pause"},
    {KEY_F1, "F1"},
    {KEY_F2, "F2"},
    {KEY_F3, "F3"},
    {KEY_F4, "F4"},
    {KEY_F5, "F5"},
    {KEY_F6, "F6"},
    {KEY_F7, "F7"},
    {KEY_F8, "F8"},
    {KEY_F9, "F9"},
    {KEY_F10, "F10"},
    {KEY_F11, "F11"},
    {KEY_F12, "F12"},
    {KEY_KB_MENU, "KB Menu"},
    {KEY_KP_0, "Num 0"},
    {KEY_KP_1, "Num 1"},
    {KEY_KP_2, "Num 2"},
    {KEY_KP_3, "Num 3"},
    {KEY_KP_4, "Num 4"},
    {KEY_KP_5, "Num 5"},
    {KEY_KP_6, "Num 6"},
    {KEY_KP_7, "Num 7"},
    {KEY_KP_8, "Num 8"},
    {KEY_KP_9, "Num 9"},
    {KEY_KP_DECIMAL, "Num dec"},
    {KEY_KP_DIVIDE, "Num div"},
    {KEY_KP_MULTIPLY, "Num mul"},
    {KEY_KP_SUBTRACT, "Num sub"},
    {KEY_KP_ADD, "Num add"},
    {KEY_KP_ENTER, "Num enter"},
    {KEY_KP_EQUAL, "Num equal"}
};

std::unordered_map<unsigned int, std::string> KeyboardHandler::LETTERMAP = {
    {KEY_A, "a"},
    {KEY_B, "b"},
    {KEY_C, "c"},
    {KEY_D, "d"},
    {KEY_E, "e"},
    {KEY_F, "f"},
    {KEY_G, "g"},
    {KEY_H, "h"},
    {KEY_I, "i"},
    {KEY_J, "j"},
    {KEY_K, "k"},
    {KEY_L, "l"},
    {KEY_M, "m"},
    {KEY_N, "n"},
    {KEY_O, "o"},
    {KEY_P, "p"},
    {KEY_Q, "q"},
    {KEY_R, "r"},
    {KEY_S, "s"},
    {KEY_T, "t"},
    {KEY_U, "u"},
    {KEY_V, "v"},
    {KEY_W, "w"},
    {KEY_X, "x"},
    {KEY_Y, "y"},
    {KEY_Z, "z"}
};

std::unordered_map<unsigned int, std::string> KeyboardHandler::NUMBERMAP = {
    {KEY_ZERO, "0"},
    {KEY_ONE, "1"},
    {KEY_TWO, "2"},
    {KEY_THREE, "3"},
    {KEY_FOUR, "4"},
    {KEY_FIVE, "5"},
    {KEY_SIX, "6"},
    {KEY_SEVEN, "7"},
    {KEY_EIGHT, "8"},
    {KEY_NINE, "9"}
};

std::unordered_map<unsigned int, std::string> KeyboardHandler::MODMAP = {
    {KEY_LEFT_SHIFT, "Left shift"},
    {KEY_LEFT_CONTROL, "Left ctrl"},
    {KEY_LEFT_ALT, "Left alt"},
    {KEY_LEFT_SUPER, "Left super"},
    {KEY_RIGHT_SHIFT, "Right shift"},
    {KEY_RIGHT_CONTROL, "Right ctrl"},
    {KEY_RIGHT_ALT, "Right alt"},
    {KEY_RIGHT_SUPER, "Right super"}
};