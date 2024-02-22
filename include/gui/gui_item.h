#pragma once

#include "event_handler.h"
#include "mouse_handler.h"


class Gui;
class Widget;
class WidgetGroup;


class GuiItem {

public:
    GuiItem();
    GuiItem(Gui* gui, int layer);

    virtual void events(MouseHandler* mouse_handler, EventHandler* event_handler) = 0;
    virtual void update(void) = 0;
    virtual void render(void) const = 0;

    virtual int get_layer(void) const;

    Gui* gui;

protected:
    int layer;
};


struct SortByLayer {
    bool operator()(const GuiItem* first, const GuiItem* second) const;
};
