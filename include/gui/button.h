#pragma once

#include "text_label.h"


class Button : public TextLabel {

public:
    Button();
    Button(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        Alignment alignment = TOPLEFT,
        int layer = 1
    );

    virtual void render(void) const override;

protected:

};