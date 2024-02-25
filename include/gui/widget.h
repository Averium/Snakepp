#pragma once

#include "gui_item.h"
#include "gui.h"
#include "rectangle.h"


enum Alignment {
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    CENTER,
};


class Widget : public GuiItem, public Rect {

public:
    Widget();
    Widget(WidgetGroup* group, Rect body, Alignment alignment, int layer);

    inline bool is_clicked(void) { return clicked; }
    void align(Vector position);

    virtual void events(MouseHandler& mouse, EventHandler& keyboard) override;

protected:

    Alignment alignment;

    bool focused;
    bool clicked;
    bool holded;
};