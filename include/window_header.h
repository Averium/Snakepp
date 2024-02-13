#pragma once

#include "const.h"
#include "mouse_handler.h"


class WindowHeader : public Rect {

public:
    WindowHeader();
    WindowHeader(Rect rect, const char* text);
    WindowHeader(Rect rect);

    void events(MouseHandler* mouse_handler);
    void render(void);

    void init_font(void);

private:
    const char* text = "";
    Font font;

    bool grab;
    Vector grab_position;
    Vector window_position;
};
