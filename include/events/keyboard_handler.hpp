#pragma once

#include <unordered_map>

#include "event_handler.hpp"
#include "config_data.hpp"


class KeyboardHandler : public EventHandler {

public:
    KeyboardHandler();
    KeyboardHandler(ConfigData<unsigned int>* keybinds);

    void update_keys(void);
    void save_keybinds(void) const;

    void configure_key(const std::string keyname, unsigned int keycode);

    inline std::string decode_key(const unsigned int keycode) const { return decode(KEYMAP, keycode); }
    inline std::string decode_letter(const unsigned int keycode) const { return decode(LETTERMAP, keycode); }
    inline std::string decode_number(const unsigned int keycode) const { return decode(NUMBERMAP, keycode); }

    inline bool is_letter(const unsigned int keycode) const { return LETTERMAP.contains(keycode); }
    inline bool is_number(const unsigned int keycode) const { return NUMBERMAP.contains(keycode); }

    virtual bool check(const std::string keyname, const Keymode keymode);
    bool shift(void) const;
    bool control(void) const;
    bool alt(void) const;

    unsigned int wait_for_key(void) const;

private:
    std::string decode(
        std::unordered_map<unsigned int, std::string>& map,
        const unsigned int keycode
    ) const;

    ConfigData<unsigned int>* keybinds;

    static std::unordered_map<unsigned int, std::string> KEYMAP;
    static std::unordered_map<unsigned int, std::string> MODMAP;
    static std::unordered_map<unsigned int, std::string> NUMBERMAP;
    static std::unordered_map<unsigned int, std::string> LETTERMAP;

};