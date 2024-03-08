#pragma once

#include <set>

#include "gui_item.hpp"


class WidgetGroup : public GuiItem {

public:
    WidgetGroup();
    WidgetGroup(WidgetGroup* group, int layer = UINT_ONE);

    ~WidgetGroup();

    void add_item(GuiItem* item);
    unsigned int number_of_items(void) const;

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    virtual void update(void) override;
    virtual void render(void) const override;

protected:
    unsigned int id_counter = UINT_ZERO;
    std::set<GuiItem*, SortByLayer> items;

};