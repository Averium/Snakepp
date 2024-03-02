#pragma once

#include "const.hpp"
#include "mouse_handler.hpp"
#include "text_label.hpp"


class WindowHeader : public TextLabel {

public:
    WindowHeader();
    WindowHeader(Gui* gui, Vector dim, std::string text, WidgetStyle style, int layer);

    void events(MouseHandler& mouse, EventHandler& keyboard);
    void render(void) const override;

    inline bool is_close_clicked(void) { return close_clicked; }
    inline bool is_minimuze_clicked(void) { return false; }

private:
    bool grab;
    bool close_hovered;
    bool close_clicked;

    Vector grab_position;
    Vector window_position;

    Rect close_rect;
};
