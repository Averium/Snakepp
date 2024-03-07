#include "text_input.hpp"


TextInput::TextInput() {}


TextInput::TextInput(
    WidgetGroup* group,
    Vector position,
    std::string text,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) : 
    DataLabel<std::string>(group, position, text + ": ", "", style, alignment, layer)
{}


void TextInput::clear(void) {
    set_value("");
}


void TextInput::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Widget::events(mouse, keyboard);

    if (gui->is_focused(this)) {

        if (mouse.check(MOUSE_BUTTON_LEFT, PRESS)) { gui->release(); }

        unsigned int keycode = keyboard.wait_for_key();
        unsigned int length = visible_text.size();

        switch (keycode)
        {
            case KEY_BACKSPACE:
                if (length > CONST::UINT_ZERO) {
                    visible_text.erase(length - CONST::UINT_ONE);
                }
                break;
            case KEY_ENTER:
                set_value(visible_text);
                gui->release();
                break;
            case KEY_ESCAPE:
                visible_text = value;
                gui->release();
                break;
            case KEY_SPACE:
                visible_text.append("_");
                return;
            default:
                visible_text.append(format_char(keyboard, keycode));
                break;
        }
    }
    else {
        if (is_clicked()) {
            gui->focus(this);
            visible_text = "";
        }
    }

}


std::string TextInput::format_char(KeyboardHandler& keyboard, const unsigned int keycode) const {
    
    std::string character;

    if (keyboard.is_letter(keycode)) {
        character = keyboard.decode_letter(keycode);
        if (keyboard.shift()) {
            character[CONST::UINT_ZERO] = toupper(character[CONST::UINT_ZERO]);
        }
    }
    else {
        character = keyboard.decode_key(keycode);
    }

    return (character.size() == CONST::UINT_ONE) ? character : "";
}


void TextInput::render(void) const {
    const std::string second_text = gui->is_focused(this) ? visible_text : value;

    Vector text_dim = text_dimensions(text.c_str());
    Vector data_dim = text_dimensions(second_text.c_str());

    Color primary_color = gui->is_focused(this) ? style.color_1_active : style.color_1_passive;
    Color secondary_color = is_hovered() ? style.color_2_active : style.color_2_passive;
    
    Vector text_position = (style.fixed_width > CONST::UINT_ZERO) ? Vector(width() - data_dim.x, 0) : Vector(text_dim.x, 0);

    draw_text(text.c_str(), secondary_color);
    draw_text(second_text.c_str(), primary_color, text_position);
}
