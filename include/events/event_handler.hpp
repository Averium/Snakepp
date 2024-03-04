#pragma once

#include <map>
#include <vector>
#include "key.hpp"


enum Keymode {
    PRESS,
    RELEASE,
    HOLD,
};


class EventHandler {

public:
    EventHandler(void);
    ~EventHandler();

    virtual bool check(int keycode, Keymode mode);

    virtual void add_key(int keycode);
    virtual void update(void);

protected:
    std::map<int, Key*> keymap;
};