#pragma once

#include <vector>
#include <sstream>

#include "text_label.hpp"


class TextLabelMultiline : public TextLabel {

public:
    TextLabelMultiline();
    TextLabelMultiline(
        WidgetGroup* group,
        Vector position,
        std::string text,
        unsigned int spacing,
        const WidgetStyle style,
        Alignment alignment = CENTER,
        int layer = 1
    );

    void set_text(const std::string new_text) override;

    virtual void render(void) const override;

private:
    unsigned int spacing;
    unsigned int line_height;
    std::istringstream stream;
    std::vector<std::string> lines;
};