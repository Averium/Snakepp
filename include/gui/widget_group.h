#pragma once


#include <set>
#include "gui_item.h"


class WidgetGroup : public GuiItem {

public:
    WidgetGroup();
    WidgetGroup(Gui* gui);
    
    ~WidgetGroup();

    void add_item(GuiItem* item);

    virtual void events(void) override;
    virtual void update(void) override;
    virtual void render(void) const override;

private:
    std::set<GuiItem*, SortByLayer> items;

};