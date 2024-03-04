#pragma once

#include "raylib.hpp"
#include "const.hpp"


class Key {

public:
    Key(void);
    Key(int keycode);

    virtual void update(void);
    virtual void set_keycode(int keycode);

    bool is_pressed(void) const;
    bool is_released(void) const;
    bool is_holded(void) const;

protected:

    int keycode;
    bool last_pressed;
    bool pressed;

};