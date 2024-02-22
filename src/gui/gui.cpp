#include "gui.h"


Gui::Gui() : GuiItem(this, 0) {}


void Gui::activate_item(GuiItem* item) {
    if (items.contains(item)) {
        active_items.insert(item);
    }
};

void Gui::deactivate_item(GuiItem* item) {
    if (active_items.contains(item)) {
        active_items.erase(item);
    }
};


template <typename TYPE>
void Gui::new_register(const std::string& name) {
    TYPE* value = new TYPE();

    if constexpr (std::is_same_v<TYPE, bool>) {
        bool_register[name] = value;
    } else if constexpr (std::is_same_v<TYPE, int>) {
        int_register[name] = value;
    } else if constexpr (std::is_same_v<TYPE, float>) {
        float_register[name] = value;
    }
}