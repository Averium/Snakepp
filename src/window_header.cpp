#include "window_header.hpp"
#include "debug.hpp"


WindowHeader::WindowHeader() : Rect() {}


WindowHeader::WindowHeader(Rect rect, const char* text) : Rect(rect), text(text) {
    init_font();
}

WindowHeader::WindowHeader(Rect rect) : Rect(rect) {
    init_font();
}


void WindowHeader::events(MouseHandler& mouse_handler) {

    if (collide(mouse_handler.get_position()) && mouse_handler.check(MOUSE_BUTTON_LEFT, PRESS)) {
        grab = true;
    }
    if (!mouse_handler.check(MOUSE_BUTTON_LEFT, HOLD)) {
        grab = false;
    }

    if (grab) {
        window_position = (window_position + mouse_handler.get_position() - grab_position);
        SetWindowPosition(window_position.x, window_position.y);
    }
    else {
        window_position = Vector(GetWindowPosition());
        grab_position = mouse_handler.get_position();
    }
}


void WindowHeader::render(void) {

    float text_x = (float)(CONST::HEADER_TEXT_SIZE / 4);
    float text_y = (float)(centery() - CONST::HEADER_TEXT_SIZE / 2 + 2);
    Vector2 position = {text_x, text_y};
    
    DrawRectangle(left(), top(), width(), height(), COLORS::HEADER);
    DrawTextEx(font, text, position, CONST::HEADER_TEXT_SIZE, 0, COLORS::HEADER_TEXT);
}


void WindowHeader::init_font(void) {
    font = LoadFont(PATH::FONT);
}