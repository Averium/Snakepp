#include "widget.hpp"
#include "widget_group.hpp"
#include "gui.hpp"
#include "debug.hpp"


Widget::Widget() {}

Widget::Widget(WidgetGroup* group, Rect body, Alignment alignment, int layer) :
    GuiItem(group->gui, layer), Rect(body), alignment(alignment)
{
    group->add_item(this);
}

void Widget::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    Vector mouse_position = mouse.get_position();

    focused = collide(mouse_position);
    clicked = focused && mouse.check(MOUSE_BUTTON_LEFT, PRESS);
    holded = focused && mouse.check(MOUSE_BUTTON_LEFT, HOLD);
}


void Widget::align(Vector anchor) {
    this->anchor = anchor;
    
    switch (alignment) {
        case TOPLEFT:
            topleft(anchor); break;
        case TOPRIGHT:
            topright(anchor); break;
        case BOTTOMLEFT:
            bottomleft(anchor); break;
        case BOTTOMRIGHT:
            bottomright(anchor); break;
        case CENTER:
            center(anchor); break;
        default:
            topleft(anchor); break;
    }
}
