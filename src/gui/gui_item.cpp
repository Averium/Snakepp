#include "gui_item.hpp"
#include "gui.hpp"
#include "debug.hpp"


GuiItem::GuiItem() {}


GuiItem::GuiItem(Gui* gui, int layer): gui(gui), layer(layer) {};


void GuiItem::events(MouseHandler& mouse, KeyboardHandler& keyboard) {}


void GuiItem::update(void) {}


void GuiItem::render(void) const {}


int GuiItem::get_layer(void) const { return this->layer; }


void GuiItem::set_id(unsigned int new_id) { this->id = new_id; }


unsigned int GuiItem::get_id(void) const { return this->id; }



bool SortByLayer::operator()(const GuiItem* first, const GuiItem* second) const {
    if (first->get_layer() == second->get_layer()) {
        return first->get_id() < second->get_id();
    }
    return first->get_layer() < second->get_layer();
}