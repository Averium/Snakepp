#include "gui_item.h"


GuiItem::GuiItem() {}

GuiItem::GuiItem(Gui* gui, int layer): gui(gui) {};

bool SortByLayer::operator()(const GuiItem& first, const GuiItem& second) const {
    return first.layer < second.layer;
}