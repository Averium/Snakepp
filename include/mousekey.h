#pragma once

#include "key.h"


class MouseKey : public Key {

public:
    MouseKey(int keycode);
    void update(void) override;

};