#pragma once

#include "data_label.hpp"


class Switch : public DataLabel<bool> {

public:
    Switch();
    Switch(
        WidgetGroup* group,
        Vector position,
        const std::string& text,
        const WidgetStyle style,
        bool state = false,
        const std::string& on_text = "On",
        const std::string& off_text = "Off",
        Alignment alignment = CENTER,
        int layer = 1
    );

    void relay(void);

    inline std::string value_text(void) const override { return value ? on_text : off_text; }

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;

protected:
    bool state;

    const std::string on_text;
    const std::string off_text;
};