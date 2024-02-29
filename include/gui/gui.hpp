#pragma once

#include "widget_group.hpp"
#include <string>


class Gui : public WidgetGroup {

public:
    Gui();

    void activate_item(GuiItem* item);
    void deactivate_item(GuiItem* item);
    void init_font(void);

    template <typename TYPE>
    void new_register(const std::string& name);

    void events(MouseHandler& mouse, EventHandler& keyboard) override;
    void update(void) override;
    void render(void) const override;

    Font font;

private:

    std::set<GuiItem*, SortByLayer> active_items;

    std::map<const std::string, bool*> bool_register;
    std::map<const std::string, int*> int_register;
    std::map<const std::string, float*> float_register;
};