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

    inline bool is_clicked(void) const { return clicked; }
    inline bool is_hovered(void) const { return hovered; }
    inline bool is_holded(void) const { return holded; }

    void align(Vector anchor);
    void align(void);

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;

private:

    Alignment alignment;
    Vector anchor;

    bool hovered = false;
    bool clicked = false;
    bool holded = false;
};