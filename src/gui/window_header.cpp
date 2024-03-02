#include "window_header.hpp"
#include "debug.hpp"


WindowHeader::WindowHeader() : TextLabel() {}


WindowHeader::WindowHeader(Gui* gui, Vector dim, std::string text, WidgetStyle style, int layer) :
    TextLabel(gui, Vector(), text, style, TOPLEFT, layer)
{
    size(dim);
    
    unsigned int gap = (unsigned int)(height() / 4);

    close_rect.size(gap * 2, gap * 2);
    close_rect.topright(width() - gap, gap);
    window_position = Vector(GetWindowPosition());
}


void WindowHeader::events(MouseHandler& mouse, EventHandler& keyboard) {

    Widget::events(mouse, keyboard);

    Vector mouse_position = mouse.get_position();
    bool mouse_click = mouse.check(MOUSE_BUTTON_LEFT, PRESS);
    bool mouse_hold = mouse.check(MOUSE_BUTTON_LEFT, HOLD);

    if (!mouse_hold) { grab = false; }
    else if (focused) { grab = true; }

    if (grab) {
        window_position = (window_position + mouse_position - grab_position);
        SetWindowPosition(window_position.x, window_position.y);
    }
    else {
        grab_position = mouse_position;
    }

    close_hovered = close_rect.collide(mouse_position);
    close_clicked = close_hovered && mouse_click;
}


void WindowHeader::render(void) const {
    Vector label_position = Vector(CONST::HEADER_TEXT_SIZE / 4, centery() - CONST::HEADER_TEXT_SIZE / 2 + 2);
    Color close_color = close_hovered ? style.primary_color_active : style.primary_color_passive;

    DrawRectangle(left(), top(), width(), height(), style.secondary_color_passive);
    draw_text(text.c_str(), style.secondary_color_active, label_position);

    DrawRectangle(close_rect.left(), close_rect.top(), close_rect.width(), close_rect.height(), close_color);
}
