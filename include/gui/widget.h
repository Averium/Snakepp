#pragma once

#include "gui_item.h"
#include "rectangle.h"


class Widget : public GuiItem, public Rect {

public:
    Widget(WidgetGroup* group, Rect body, int layer);

    void events(void) override;
    void update(void) override;
    void render(void) const override;

private:
    bool focused;
    bool clicked;
    bool holded;
};