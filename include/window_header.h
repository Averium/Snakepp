#pragma once

#include "const.h"
#include "event_handler.h"


class WindowHeader : public Rect {

public:
    WindowHeader();
    WindowHeader(Rect rect, const char* text);
    WindowHeader(Rect rect);

    void events(EventHandler* event_handler);
    void render(void);

    void init_font(void);

private:
    const char* text = "";
    Font font;
};