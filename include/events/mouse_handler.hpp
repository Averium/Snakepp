#pragma once

#include "mousekey.hpp"
#include "event_handler.hpp"


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