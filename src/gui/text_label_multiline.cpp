#include "text_label_multiline.hpp"
#include "gui.hpp"


TextLabelMultiline::TextLabelMultiline() : TextLabel() {}

TextLabelMultiline::TextLabelMultiline(
    WidgetGroup* group,
    Vector position,
    std::string text,
    unsigned int spacing,
    const WidgetStyle style,
    Alignment alignment,
    int layer
) :
    TextLabel(group, position, text, style, alignment, layer),
    spacing(spacing)
{
    set_text(text);
}


void TextLabelMultiline::set_text(const std::string new_text) {
    stream = std::istringstream(text);
    
    std::string line;
    unsigned int max_width = UINT_ZERO;
    unsigned int max_height = UINT_ZERO;

    while (std::getline(stream, line, '\n')) {
        this->lines.push_back(line);

        Vector line_size = text_dimensions(line.c_str());
        this->line_height = line_size.y + spacing;

        max_width = (line_size.x > max_width) ? line_size.x : max_width;
        max_height += line_height;
    }

    width(max_width);
    height(max_height);
    align();
}


void TextLabelMultiline::render(void) const {
    
    unsigned int height = UINT_ZERO;
    for (const std::string& line : lines) {
        draw_text(line.c_str(), style.color_1_passive, Vector(UINT_ZERO, height));
        height += line_height;
    }
}

