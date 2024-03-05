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
        Alignment alignment = TOPLEFT,
        int layer = CONST::UINT_ONE
    );

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;
    virtual void render(void) const override;

private:
    std::string visible_text;

};