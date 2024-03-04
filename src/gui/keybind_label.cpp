#include "keybind_label.hpp"


KeybindLabel::KeybindLabel() {}


KeybindLabel::KeybindLabel(
    WidgetGroup* group,
    Vector position,
    std::string text,
    unsigned int width,
    unsigned int keycode,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) :
    TextLabel(group, position, text, style, alignment, layer),
    key_text(KEYMAP[keycode])
{
    this->width(width);
    this->align(position);
}


void KeybindLabel::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (gui->is_focused(this)) {
        if (mouse.check(MOUSE_BUTTON_LEFT, PRESS)) {
            gui->release();
        }

        unsigned int keycode = keyboard.wait_for_key();

        if (keycode != KEY_NULL) {
            keyboard.configure_key(this->text, keycode);
            key_text = KEYMAP[keycode];
            gui->release();
        }

    }
    else {
        if (clicked) { gui->focus(this); }
    }
}


void KeybindLabel::render(void) const {
    std::string left_text = gui->is_focused(this) ? placeholder : key_text;

    Vector value_dim = text_dimensions(left_text.c_str());

    Color primary_color = hovered ? style.color_1_active : style.color_1_passive;
    Color secondary_color = hovered ? style.color_2_active : style.color_2_passive;
    
    draw_text(text.c_str(), secondary_color);
    draw_text(left_text.c_str(), primary_color, Vector(width() - value_dim.x, 0));
}


const std::string KeybindLabel::placeholder = "Press a key";


std::unordered_map<unsigned int, std::string> KeybindLabel::KEYMAP = {
    {KEY_NULL, "NULL"},
    {KEY_APOSTROPHE, "APOSTROPHE"},
    {KEY_COMMA, "COMMA"},
    {KEY_MINUS, "MINUS"},
    {KEY_PERIOD, "PERIOD"},
    {KEY_SLASH, "SLASH"},
    {KEY_ZERO, "ZERO"},
    {KEY_ONE, "ONE"},
    {KEY_TWO, "TWO"},
    {KEY_THREE, "THREE"},
    {KEY_FOUR, "FOUR"},
    {KEY_FIVE, "FIVE"},
    {KEY_SIX, "SIX"},
    {KEY_SEVEN, "SEVEN"},
    {KEY_EIGHT, "EIGHT"},
    {KEY_NINE, "NINE"},
    {KEY_SEMICOLON, "SEMICOLON"},
    {KEY_EQUAL, "EQUAL"},
    {KEY_A, "A"},
    {KEY_B, "B"},
    {KEY_C, "C"},
    {KEY_D, "D"},
    {KEY_E, "E"},
    {KEY_F, "F"},
    {KEY_G, "G"},
    {KEY_H, "H"},
    {KEY_I, "I"},
    {KEY_J, "J"},
    {KEY_K, "K"},
    {KEY_L, "L"},
    {KEY_M, "M"},
    {KEY_N, "N"},
    {KEY_O, "O"},
    {KEY_P, "P"},
    {KEY_Q, "Q"},
    {KEY_R, "R"},
    {KEY_S, "S"},
    {KEY_T, "T"},
    {KEY_U, "U"},
    {KEY_V, "V"},
    {KEY_W, "W"},
    {KEY_X, "X"},
    {KEY_Y, "Y"},
    {KEY_Z, "Z"},
    {KEY_LEFT_BRACKET, "LEFT_BRACKET"},
    {KEY_BACKSLASH, "BACKSLASH"},
    {KEY_RIGHT_BRACKET, "RIGHT_BRACKET"},
    {KEY_GRAVE, "GRAVE"},
    {KEY_SPACE, "SPACE"},
    {KEY_ESCAPE, "ESCAPE"},
    {KEY_ENTER, "ENTER"},
    {KEY_TAB, "TAB"},
    {KEY_BACKSPACE, "BACKSPACE"},
    {KEY_INSERT, "INSERT"},
    {KEY_DELETE, "DELETE"},
    {KEY_RIGHT, "RIGHT"},
    {KEY_LEFT, "LEFT"},
    {KEY_DOWN, "DOWN"},
    {KEY_UP, "UP"},
    {KEY_PAGE_UP, "PAGE_UP"},
    {KEY_PAGE_DOWN, "PAGE_DOWN"},
    {KEY_HOME, "HOME"},
    {KEY_END, "END"},
    {KEY_CAPS_LOCK, "CAPS_LOCK"},
    {KEY_SCROLL_LOCK, "SCROLL_LOCK"},
    {KEY_NUM_LOCK, "NUM_LOCK"},
    {KEY_PRINT_SCREEN, "PRINT_SCREEN"},
    {KEY_PAUSE, "PAUSE"},
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
    {KEY_LEFT_SHIFT, "LEFT_SHIFT"},
    {KEY_LEFT_CONTROL, "LEFT_CONTROL"},
    {KEY_LEFT_ALT, "LEFT_ALT"},
    {KEY_LEFT_SUPER, "LEFT_SUPER"},
    {KEY_RIGHT_SHIFT, "RIGHT_SHIFT"},
    {KEY_RIGHT_CONTROL, "RIGHT_CONTROL"},
    {KEY_RIGHT_ALT, "RIGHT_ALT"},
    {KEY_RIGHT_SUPER, "RIGHT_SUPER"},
    {KEY_KB_MENU, "KB_MENU"},
    {KEY_KP_0, "KP_0"},
    {KEY_KP_1, "KP_1"},
    {KEY_KP_2, "KP_2"},
    {KEY_KP_3, "KP_3"},
    {KEY_KP_4, "KP_4"},
    {KEY_KP_5, "KP_5"},
    {KEY_KP_6, "KP_6"},
    {KEY_KP_7, "KP_7"},
    {KEY_KP_8, "KP_8"},
    {KEY_KP_9, "KP_9"},
    {KEY_KP_DECIMAL, "KP_DECIMAL"},
    {KEY_KP_DIVIDE, "KP_DIVIDE"},
    {KEY_KP_MULTIPLY, "KP_MULTIPLY"},
    {KEY_KP_SUBTRACT, "KP_SUBTRACT"},
    {KEY_KP_ADD, "KP_ADD"},
    {KEY_KP_ENTER, "KP_ENTER"},
    {KEY_KP_EQUAL, "KP_EQUAL"},
};