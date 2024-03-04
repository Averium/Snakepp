#include "keybind_state.hpp"
#include "game.hpp"


KeyBindsState::KeyBindsState(Game* game) : GameState(KEYBINDS_STATE, game) {}

GameStateId KeyBindsState::conditions(void) const {
    if (game->keybinds_back_button->is_clicked()) { return MENU_STATE; }
    return KEYBINDS_STATE;
}


void KeyBindsState::on_entry(void) {
    game->gui->activate_item(game->keybinds_group);
}


void KeyBindsState::on_exit(void) {
    game->gui->deactivate_item(game->keybinds_group);
    game->keyboard.save_keybinds();
}