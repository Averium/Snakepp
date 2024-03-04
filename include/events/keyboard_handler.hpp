#pragma once

#include "event_handler.hpp"
#include "config_data.hpp"


class KeyboardHandler : public EventHandler {

public:
    KeyboardHandler();
    KeyboardHandler(ConfigData<unsigned int>* keybinds);

    void update_keys(void);
    void save_keybinds(void);

    void configure_key(const std::string keyname, unsigned int keycode);

    bool check(const std::string keyname, Keymode keymode);
    unsigned int wait_for_key(void);

private:
    ConfigData<unsigned int>* keybinds;

};