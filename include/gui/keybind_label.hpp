#pragma once

#include <unordered_map>

#include "data_label.hpp"


class KeybindLabel : public DataLabel<std::string> {

public:
    KeybindLabel();
    KeybindLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        std::string keyname,
        const WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = 1
    );

    virtual std::string value_text(void) const override;
    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard);

private:
    std::string key_text;
    static const std::string placeholder;
};