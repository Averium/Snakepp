#pragma once

#include "keyboard_handler.hpp"
#include "mouse_handler.hpp"
#include "color_data.hpp"


class Gui;
class Widget;
class WidgetGroup;


class GuiItem {

public:
    GuiItem();
    GuiItem(Gui* gui, int layer);

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard);
    virtual void update(void);
    virtual void render(ColorData& colors) const;

    virtual int get_layer(void) const;
    
    void set_id(unsigned int new_id);
    unsigned int get_id(void) const;

    Gui* gui = nullptr;

protected:
    int layer;
    unsigned int id;
};


struct SortByLayer {
    bool operator()(const GuiItem* first, const GuiItem* second) const;
};
