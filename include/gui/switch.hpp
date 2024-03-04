#pragma once

#include "data_label.hpp"


class Switch : public DataLabel<bool> {

public:
    Switch();
    Switch(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        bool state = false,
        Alignment alignment = TOPLEFT,
        int layer = 1
    );

    void relay(void);

    inline std::string value_text(void) const override { return value ? "On" : "Off"; }

    virtual void events(MouseHandler& mouse, KeyboardHandler& keyboard) override;

protected:
    bool state;
};