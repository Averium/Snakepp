#include "widget_group.h"
#include "gui.h"


WidgetGroup::WidgetGroup() {}


WidgetGroup::WidgetGroup(WidgetGroup* group, int layer) : GuiItem(group->gui, layer) {
    group->add_item(this);
}

WidgetGroup::~WidgetGroup() {
    for (GuiItem* item : items) { delete item; }
}

void WidgetGroup::add_item(GuiItem* item) {
    items.insert(item);
}

void WidgetGroup::events(MouseHandler* mouse_handler, EventHandler* event_handler) {
    for (GuiItem* item : items) { item->events(mouse_handler, event_handler); }
}

void WidgetGroup::update(void) {
    for (GuiItem* item : items) { item->update(); }
}

void WidgetGroup::render(void) const {
    for (GuiItem* item : items) { item->render(); }
}