#pragma once

#include <string>

#include "widget.hpp"
#include "widget_style.hpp"


class TextLabel : public Widget {

public:
    TextLabel();
    TextLabel(
        WidgetGroup* group,
        Vector position,
        std::string text,
        const WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = 1
    );

    void set_text(const std::string new_text);

    Vector text_dimensions(const char* text) const;
    void draw_text(const char* text, Color color, Vector position = Vector()) const;

    virtual void render(void) const override;

protected:
    std::string text;
    const WidgetStyle style;
};