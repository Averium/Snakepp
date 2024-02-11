#pragma once

#include "raylib.h"
#include "const.h"


class Key {

public:
    Key(void);
    Key(int keycode);

    void update(void);

    bool is_pressed(void) const;
    bool is_released(void) const;
    bool is_holded(void) const;

private:

    int keycode;
    bool last_pressed;
    bool pressed;

};