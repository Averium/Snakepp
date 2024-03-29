#include "gui.hpp"
#include "widget.hpp"
#include "debug.hpp"


Gui::Gui() : WidgetGroup(this, 0) {
    this->gui = this;
    init_font();
}


void Gui::activate_item(GuiItem* item) {
    if (items.contains(item)) {
        active_items.insert(item);
    }
}


void Gui::deactivate_item(GuiItem* item) {
    if (active_items.contains(item)) {
        active_items.erase(item);
    }
}


void Gui::focus(Widget* widget) {
    focused_widget = widget;
}


void Gui::release(void) {
    focused_widget = nullptr;
}


bool Gui::is_focused(const Widget* widget) const {
    return widget == focused_widget;
}


bool Gui::is_focused(void) const {
    return focused_widget != nullptr;
}


Widget* Gui::get_focused_widget(void) const {
    return focused_widget;
}


void Gui::init_font(void) {
    font = LoadFont(PATH::FONT.c_str());
}


void Gui::events(MouseHandler& mouse, KeyboardHandler& keyboard) {
    if (is_focused()) {
        focused_widget->events(mouse, keyboard);
    }
    else {
        for (GuiItem* item : active_items) {
            item->events(mouse, keyboard);
        }
    }
}


void Gui::update(void) {
    for (GuiItem* item : active_items) {
        item->update();
    }
}


void Gui::render(ColorData& colors) const {
    for (GuiItem* item : active_items) {
        item->render(colors);
    }
}