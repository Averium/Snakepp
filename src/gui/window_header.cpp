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

    minimize_rect.size(gap * 2, gap * 2);
    minimize_rect.topright(close_rect.left() - gap, gap);

    window_position = Vector(GetWindowPosition());
}


void WindowHeader::events(MouseHandler& mouse, KeyboardHandler& keyboard) {

    Widget::events(mouse, keyboard);

    Vector mouse_position = mouse.get_position();
    bool mouse_click = mouse.check(MOUSE_BUTTON_LEFT, PRESS);
    bool mouse_hold = mouse.check(MOUSE_BUTTON_LEFT, HOLD);

    if (!mouse_hold) { grab = false; }
    else if (hovered) { grab = true; }

    if (grab) {
        window_position = (window_position + mouse_position - grab_position);
        SetWindowPosition(window_position.x, window_position.y);
    }
    else {
        grab_position = mouse_position;
    }

    close_hovered = close_rect.collide(mouse_position);
    minimize_hovered = minimize_rect.collide(mouse_position);

    close_clicked = close_hovered && mouse_click;
    minimize_clicked = minimize_hovered && mouse_click;
}


void WindowHeader::render(void) const {
    Vector label_position = Vector(style.font_size / 4, centery() - style.font_size / 2 + 2);
    Color close_color = close_hovered ? style.color_2_active : style.color_2_passive;
    Color minimize_color = minimize_hovered ? style.color_3_active : style.color_3_passive;

    DrawRectangle(left(), top(), width(), height(), style.color_1_passive);
    draw_text(text.c_str(), style.color_1_active, label_position);

    DrawRectangle(close_rect.left(), close_rect.top(), close_rect.width(), close_rect.height(), close_color);
    DrawRectangle(minimize_rect.left(), minimize_rect.top(), minimize_rect.width(), minimize_rect.height(), minimize_color);
}
