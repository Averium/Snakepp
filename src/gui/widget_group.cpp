#include "widget_group.h"
#include "gui.h"
#include "debug.h"


WidgetGroup::WidgetGroup() {}


WidgetGroup::WidgetGroup(WidgetGroup* group, int layer) : GuiItem(group->gui, layer) {
    if (group != this) {
        group->add_item(this);
    }
}

WidgetGroup::~WidgetGroup() {
    for (GuiItem* item : items) { delete item; }
}

void WidgetGroup::add_item(GuiItem* item) {
    items.insert(item);
}

unsigned int WidgetGroup::number_of_items(void) const {
    return items.size();
}

void WidgetGroup::events(MouseHandler& mouse, EventHandler& keyboard) {
    for (GuiItem* item : items) {
        item->events(mouse, keyboard);
    }
}

void WidgetGroup::update(void) {
    for (GuiItem* item : items) { item->update(); }
}

void WidgetGroup::render(void) const {
    for (GuiItem* item : items) { item->render(); }
}