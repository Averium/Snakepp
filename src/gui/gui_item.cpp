#include "gui_item.hpp"
#include "gui.hpp"
#include "debug.hpp"


GuiItem::GuiItem() {}


GuiItem::GuiItem(Gui* gui, int layer): gui(gui), layer(layer) {};


void GuiItem::events(MouseHandler& mouse, EventHandler& keyboard) {}


void GuiItem::update(void) {}


void GuiItem::render(void) const {}


int GuiItem::get_layer(void) const { return this->layer; }


bool SortByLayer::operator()(const GuiItem* first, const GuiItem* second) const {
    return first->get_layer() < second->get_layer();
}