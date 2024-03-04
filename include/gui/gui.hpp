#pragma once

#include <string>

#include "widget_group.hpp"


class Gui : public WidgetGroup {

public:
    Gui();

    void activate_item(GuiItem* item);
    void deactivate_item(GuiItem* item);
    void init_font(void);

    template <typename TYPE>
    void new_register(const std::string& name);

    void focus(Widget* widget);
    void release(void);
    
    bool is_focused(const Widget* widget) const;
    bool is_focused(void) const;
    Widget* get_focused_widget(void) const;

    void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    void update(void) override;
    void render(void) const override;

    Font font;

private:

    std::set<GuiItem*, SortByLayer> active_items;

    std::map<const std::string, bool*> bool_register;
    std::map<const std::string, int*> int_register;
    std::map<const std::string, float*> float_register;

    Widget* focused_widget = nullptr;
};