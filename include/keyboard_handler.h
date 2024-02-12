#pragma once
#include <map>
#include <vector>
#include "key.h"


enum keymode {
    PRESS,
    RELEASE,
    HOLD,
};


class KeyboardHandler {

public:
    KeyboardHandler(void);

    bool check(int keycode, keymode mode);
    void add_key(int keycode);

    void update(void);

private:
    std::map<int, Key> keymap;
    std::vector<Key*> keyref;
};