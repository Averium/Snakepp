#pragma once

#include <set>

#include "gui_item.hpp"


class WidgetGroup : public GuiItem {

public:
    WidgetGroup();
    WidgetGroup(WidgetGroup* group, int layer = 1);

    ~WidgetGroup();

    void add_item(GuiItem* item);
    unsigned int number_of_items(void) const;

    virtual void events(MouseHandler& mouse, EventHandler& keyboard) override;
    virtual void update(void) override;
    virtual void render(void) const override;

protected:
    std::set<GuiItem*, SortByLayer> items;

};