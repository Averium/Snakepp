#pragma once

#include "gui_item.hpp"
#include "gui.hpp"
#include "rectangle.hpp"


enum Alignment {
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    MIDLEFT,
    MIDRIGHT,
    MIDTOP,
    MIDBOTTOM,
    CENTER,
};


class Widget : public GuiItem, public Rect {

public:
    Widget();
    Widget(WidgetGroup* group, Rect body, Alignment alignment, int layer);

    inline bool is_clicked(void) { return clicked; }
    void align(Vector anchor);

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;

    bool hovered = false;
protected:

    Alignment alignment;
    Vector anchor;

    bool clicked = false;
    bool holded = false;
};