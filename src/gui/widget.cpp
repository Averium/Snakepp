#include "widget.h"
#include "widget_group.h"
#include "integer_vector.h"


Widget::Widget(WidgetGroup* group, Rect body, int layer): GuiItem(group->gui, layer), Rect(body) {}

void Widget::events(MouseHandler* mouse_handler, EventHandler* event_handler) {
    Vector mouse_position = mouse_handler->get_position();

    focused = collide(mouse_position);
    clicked = focused && mouse_handler->check(MOUSE_BUTTON_LEFT, PRESS);
    holded = focused && mouse_handler->check(MOUSE_BUTTON_LEFT, HOLD);
}

void Widget::update(void) {}

void Widget::render(void) const {}