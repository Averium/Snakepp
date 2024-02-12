#include "window_header.h"
#include <string>


WindowHeader::WindowHeader() : Rect() {}


WindowHeader::WindowHeader(Rect rect, const char* text) : Rect(rect), text(text) {
    init_font();
}


WindowHeader::WindowHeader(Rect rect) : Rect(rect) {
    init_font();
}


void WindowHeader::events(EventHandler* event_handler) {

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