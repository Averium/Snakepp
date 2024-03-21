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


void TextInput::blink_cursor(void) {
    if (cursor_timer.tick()) { cursor_visible = !cursor_visible; }
}


void TextInput::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    DataLabel::events(mouse, keyboard);

    if (gui->is_focused(this)) {
        blink_cursor();

        if (mouse.check(MOUSE_BUTTON_LEFT, PRESS)) {
            if (visible_text != "") { set_value(visible_text); }
            gui->release();
        }

        unsigned int keycode = keyboard.wait_for_key();
        unsigned int length = visible_text.size();

        switch (keycode)
        {
            case KEY_BACKSPACE:
                if (length > UINT_ZERO) {
                    visible_text.erase(length - UINT_ONE);
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
            cursor_visible = true;
            cursor_timer.reset();
        }
    }

}


std::string TextInput::format_char(KeyboardHandler& keyboard, const unsigned int keycode) const {
    
    std::string character;

    if (keyboard.is_letter(keycode)) {
        character = keyboard.decode_letter(keycode);
        if (keyboard.shift()) {
            character[UINT_ZERO] = toupper(character[UINT_ZERO]);
        }
    }
    else {
        character = keyboard.decode_key(keycode);
    }

    return (character.size() == UINT_ONE) ? character : "";
}


void TextInput::render(ColorData& colors) const {

    const std::string second_text = is_focused() ? visible_text : value;
    const std::string cursor_text = is_focused() && cursor_visible ? "I" : " ";

    Vector text_dim = text_dimensions(text.c_str());
    Vector data_dim = text_dimensions(second_text.c_str());
    Vector cursor_dim = text_dimensions(" ");

    const std::string primary_color = is_focused() ? style.color_1_active : style.color_1_passive;
    const std::string secondary_color = is_hovered() ? style.color_2_active : style.color_2_passive;
    
    Vector text_position = (style.fixed_width > UINT_ZERO) ? Vector(width() - data_dim.x - cursor_dim.x, UINT_ZERO) : Vector(text_dim.x, UINT_ZERO);
    Vector cursor_position = (style.fixed_width > UINT_ZERO) ? Vector(width() - cursor_dim.x, UINT_ZERO) : Vector(text_dim.x + cursor_dim.x, UINT_ZERO);

    draw_text(text.c_str(), colors(secondary_color));
    draw_text(second_text.c_str(), colors(primary_color), text_position);
    draw_text(cursor_text.c_str(), colors(secondary_color), cursor_position);
}
