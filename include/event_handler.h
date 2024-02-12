#pragma once
#include <map>
#include <vector>
#include "key.h"
#include "debug.h"


enum keymode {
    PRESS,
    RELEASE,
    HOLD,
};


class EventHandler {

public:
    EventHandler(void);
    ~EventHandler();

    bool check(int keycode, keymode mode);

    virtual void add_key(int keycode);
    virtual void update(void);

protected:
    std::map<int, Key*> keymap;
    std::vector<Key*> keyref;
};