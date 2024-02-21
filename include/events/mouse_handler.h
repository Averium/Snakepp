#pragma once

#include "mousekey.h"
#include "event_handler.h"


class MouseHandler : public EventHandler {

public:
    MouseHandler(void);

    void update(void) override;
    void add_key(int keycode) override;

    inline Vector get_position(void) const { return position; }
    inline Vector get_drag(void) const { return drag; }

private:
    Vector position;
    Vector last_position;
    Vector anchor;
    Vector drag;
};