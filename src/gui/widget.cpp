#include "widget.h"
#include "widget_group.h"
#include "gui.h"
#include "debug.h"


Widget::Widget() {}

Widget::Widget(WidgetGroup* group, Rect body, Vector anchor, Align align, int layer) :
    GuiItem(group->gui, layer), Rect(body), anchor(anchor), align(align)
{
    group->add_item(this);
}

void Widget::events(MouseHandler& mouse, EventHandler& keyboard) {
    Vector mouse_position = mouse.get_position();

    focused = collide(mouse_position);
    clicked = focused && mouse.check(MOUSE_BUTTON_LEFT, PRESS);
    holded = focused && mouse.check(MOUSE_BUTTON_LEFT, HOLD);
}