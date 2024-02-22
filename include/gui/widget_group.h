#pragma once


#include <set>
#include "gui_item.h"


class WidgetGroup : virtual public GuiItem {

public:
    WidgetGroup();
    WidgetGroup(WidgetGroup* group, int layer = 1);

    ~WidgetGroup();

    void add_item(GuiItem* item);

    virtual void events(MouseHandler* mouse_handler, EventHandler* event_handler) override;
    virtual void update(void) override;
    virtual void render(void) const override;

protected:
    std::set<GuiItem*, SortByLayer> items;

};