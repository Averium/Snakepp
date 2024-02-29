#pragma once

#include "event_handler.hpp"
#include "mouse_handler.hpp"


class Gui;
class Widget;
class WidgetGroup;


class GuiItem {

public:
    GuiItem();
    GuiItem(Gui* gui, int layer);

    virtual void events(MouseHandler& mouse, EventHandler& keyboard);
    virtual void update(void);
    virtual void render(void) const;

    virtual int get_layer(void) const;

    Gui* gui = nullptr;

protected:
    int layer;
};


struct SortByLayer {
    bool operator()(const GuiItem* first, const GuiItem* second) const;
};
