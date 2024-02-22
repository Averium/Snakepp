#pragma once

#include "widget_group.h"
#include <string>


class Gui : public WidgetGroup {

public:
    Gui();

private:

    std::set<GuiItem*, SortByLayer> active_items;

    template <typename TYPE>
    void new_register(const std::string& name);

    std::map<const std::string, bool*> bool_register;
    std::map<const std::string, int*> int_register;
    std::map<const std::string, float*> float_register;

    void activate_item(GuiItem* item);
    void deactivate_item(GuiItem* item);
};