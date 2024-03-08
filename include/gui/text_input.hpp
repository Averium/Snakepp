#pragma once

#include <string>

#include "data_label.hpp"
#include "timer.hpp"


class TextInput : public DataLabel<std::string> {

public:
    TextInput();
    TextInput(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = UINT_ONE
    );

    std::string format_char(KeyboardHandler& keyboard, const unsigned int keycode) const;
    virtual void clear(void);

    void blink_cursor(void);

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    virtual void render(void) const override;

private:
    bool cursor_visible = true;
    std::string visible_text;

    Timer cursor_timer = Timer(CURSOR_FLASH_PERIOD);
};