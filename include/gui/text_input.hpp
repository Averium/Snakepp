#pragma once

#include <string>

#include "data_label.hpp"


class TextInput : public DataLabel<std::string> {

public:
    TextInput();
    TextInput(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = CONST::UINT_ONE
    );

    std::string format_char(KeyboardHandler& keyboard, const unsigned int keycode) const;
    virtual void clear(void);

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    virtual void render(void) const override;

private:
    bool value_changed = false;
    std::string visible_text;
};