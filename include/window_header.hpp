#pragma once

#include "const.hpp"
#include "mouse_handler.hpp"


class WindowHeader : public Rect {

public:
    WindowHeader();
    WindowHeader(Vector dim);
    WindowHeader(Vector dim, const char* text);

    void events(MouseHandler& mouse_handler);
    void render(void);

    void init_font(void);

private:
    const char* text = "";
    Font font;

    bool grab;
    Vector grab_position;
    Vector window_position;
};
