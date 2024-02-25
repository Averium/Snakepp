#pragma once


#include <string>
#include "widget.h"


class TextLabel : public Widget {

public:
    TextLabel();
    TextLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        unsigned char text_size = 40U,
        Vector anchor = Vector(0U, 0U),
        Align align = TOPLEFT,
        int layer = 1
    );

    void render(void) const override;

protected:
    std::string text;
    unsigned char text_size = 40;
};