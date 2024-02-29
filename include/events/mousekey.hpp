#pragma once

#include "key.hpp"


class MouseKey : public Key {

public:
    MouseKey(int keycode);
    void update(void) override;

};