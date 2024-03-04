#pragma once

#include <unordered_map>

#include "text_label.hpp"


class KeybindLabel : public TextLabel {

public:
    KeybindLabel();
    KeybindLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        unsigned int width,
        unsigned int keycode,
        const WidgetStyle style,
        Alignment alignment = TOPLEFT,
        int layer = 1
    );

    void events(MouseHandler& mouse, KeyboardHandler& keyboard);
    void render(void) const;

private:
    std::string key_text;

    static const std::string placeholder;
    static std::unordered_map<unsigned int, std::string> KEYMAP;
};