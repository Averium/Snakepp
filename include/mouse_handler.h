#pragma once
#include <map>
#include <vector>
#include "mousekey.h"
#include "event_handler.h"


class MouseHandler : public EventHandler {

public:
    MouseHandler(void);

    void update(void) override;
    void add_key(int keycode) override;

};