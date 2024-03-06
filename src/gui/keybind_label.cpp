#include "keybind_label.hpp"


KeybindLabel::KeybindLabel() {}


KeybindLabel::KeybindLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    unsigned int keycode,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) :
    DataLabel<std::string>(group, position, text, KEYMAP[keycode], style, alignment, layer),
    key_text(KEYMAP[keycode])
{}


void KeybindLabel::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (gui->is_focused(this)) {
        if (mouse.check(MOUSE_BUTTON_LEFT, PRESS)) {
            gui->release();
        }

        unsigned int keycode = keyboard.wait_for_key();

        if (keycode != KEY_NULL) {
            keyboard.configure_key(this->text, keycode);
            set_value(KEYMAP[keycode]);
            gui->release();
        }

    }
    else {
        if (clicked) { gui->focus(this); }
    }
}


std::string KeybindLabel::value_text(void) const {
    return gui->is_focused(this) ? placeholder : value;
}


const std::string KeybindLabel::placeholder = "Press a key";


std::unordered_map<unsigned int, std::string> KeybindLabel::KEYMAP = {
    {KEY_NULL, "NULL"},
    {KEY_APOSTROPHE, "'"},
    {KEY_COMMA, ","},
    {KEY_MINUS, "-"},
    {KEY_PERIOD, "."},
    {KEY_SLASH, "/"},
    {KEY_ZERO, "0"},
    {KEY_ONE, "1"},
    {KEY_TWO, "2"},
    {KEY_THREE, "3"},
    {KEY_FOUR, "4"},
    {KEY_FIVE, "5"},
    {KEY_SIX, "6"},
    {KEY_SEVEN, "7"},
    {KEY_EIGHT, "8"},
    {KEY_NINE, "9"},
    {KEY_SEMICOLON, ";"},
    {KEY_EQUAL, "="},
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
    {KEY_Z, "z"},
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
    {KEY_LEFT_SHIFT, "Left shift"},
    {KEY_LEFT_CONTROL, "Left ctrl"},
    {KEY_LEFT_ALT, "Left alt"},
    {KEY_LEFT_SUPER, "Left super"},
    {KEY_RIGHT_SHIFT, "Right shift"},
    {KEY_RIGHT_CONTROL, "Right ctrl"},
    {KEY_RIGHT_ALT, "Right alt"},
    {KEY_RIGHT_SUPER, "Right super"},
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
    {KEY_KP_EQUAL, "Num equal"},
};