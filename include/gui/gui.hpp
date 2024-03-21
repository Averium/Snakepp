#pragma once

#include <string>

#include "widget_group.hpp"


class Gui : public WidgetGroup {

public:
    Gui();

    void activate_item(GuiItem* item);
    void deactivate_item(GuiItem* item);
    void init_font(void);

    void focus(Widget* widget);
    void release(void);
    bool is_focused(const Widget* widget) const;
    bool is_focused(void) const;
    Widget* get_focused_widget(void) const;

    void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    void update(void) override;
    void render(ColorData& colors) const override;

    Font font;

private:
    std::set<GuiItem*, SortByLayer> active_items;
    Widget* focused_widget = nullptr;
};