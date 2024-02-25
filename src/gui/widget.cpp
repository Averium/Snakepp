#include "widget.h"
#include "widget_group.h"
#include "gui.h"
#include "debug.h"


Widget::Widget() {}

Widget::Widget(WidgetGroup* group, Rect body, Alignment alignment, int layer) :
    GuiItem(group->gui, layer), Rect(body), alignment(alignment)
{
    group->add_item(this);
}

void Widget::events(MouseHandler& mouse, EventHandler& keyboard) {
    Vector mouse_position = mouse.get_position();

    focused = collide(mouse_position);
    clicked = focused && mouse.check(MOUSE_BUTTON_LEFT, PRESS);
    holded = focused && mouse.check(MOUSE_BUTTON_LEFT, HOLD);
}


void Widget::align(Vector position) {
    switch (alignment) {
        case TOPLEFT:
            topleft(position); break;
        case TOPRIGHT:
            topright(position); break;
        case BOTTOMLEFT:
            bottomleft(position); break;
        case BOTTOMRIGHT:
            bottomright(position); break;
        case CENTER:
            center(position); break;
        default:
            topleft(position); break;
    }
}
