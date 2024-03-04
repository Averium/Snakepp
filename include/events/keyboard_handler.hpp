#pragma once

#include "event_handler.hpp"
#include "config_data.hpp"


class KeyboardHandler : public EventHandler {

public:
    KeyboardHandler();
    KeyboardHandler(ConfigData<unsigned int>* keybinds);

    bool check(const std::string key, Keymode keymode);

private:
    ConfigData<unsigned int>* keybinds;

};