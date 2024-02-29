#pragma once

#include "text_label.hpp"


class Switch : public TextLabel {

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
    void relay(bool state);

    inline std::string state_text(void) const { return state ? "On" : "Off"; }

    virtual void events(MouseHandler& mouse, EventHandler& keyboard) override;
    virtual void render(void) const override;

protected:
    bool state;

private:
    void update_size(void);
};