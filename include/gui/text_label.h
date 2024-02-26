#pragma once


#include <string>
#include "widget.h"
#include "widget_style.h"


class TextLabel : public Widget {

public:
    TextLabel();
    TextLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        Alignment alignment = TOPLEFT,
        int layer = 1
    );

    Vector text_dimensions(const char* text) const;
    void draw_text(const char* text, Color color, Vector position = Vector()) const;

    virtual void render(void) const override;

protected:
    std::string text;
    const WidgetStyle style;
};