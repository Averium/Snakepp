#pragma once


#include "widget_group.h"


class Gui : public WidgetGroup {

public:
    Gui();
    ~Gui();

    void events(void) override;
    void update(void) override;
    void render(void) const override;

private:

    std::set<GuiItem*, SortByLayer> active_items;

    void activate_items(GuiItem* item[]);
    void deactivate_items(GuiItem* item[]);
};