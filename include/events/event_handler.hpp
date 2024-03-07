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

    virtual bool check(const unsigned int keycode, const Keymode mode);

    virtual void add_key(const unsigned int keycode);
    virtual void update(void);

protected:
    std::map<const unsigned int, Key*> keymap;
};