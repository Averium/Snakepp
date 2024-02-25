#pragma once

#include "gui_item.h"
#include "gui.h"
#include "rectangle.h"


enum Align {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    CENTER,
};


class Widget : public GuiItem, public Rect {

public:
    Widget();
    Widget(WidgetGroup* group, Rect body, Vector anchor, Align align, int layer);

    virtual void events(MouseHandler& mouse, EventHandler& keyboard) override;

protected:
    Vector anchor;
    Align align;

    bool focused;
    bool clicked;
    bool holded;
};