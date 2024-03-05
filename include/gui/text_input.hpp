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
        Alignment alignment = CENTER,
        int layer = CONST::UINT_ONE
    );

private:


};