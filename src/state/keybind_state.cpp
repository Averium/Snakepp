#include "keybind_state.hpp"
#include "game.hpp"


KeyBindsState::KeyBindsState(
    Game* game
) : 
    GuiState(KEYBINDS_STATE, game, game->keybinds_group) {}

GameStateId KeyBindsState::conditions(void) const {
    if (game->keybinds_back_button->is_clicked()) { return MENU_STATE; }
    return KEYBINDS_STATE;
}


void KeyBindsState::on_exit(void) {
    GuiState::on_exit();
    game->keyboard.save_keybinds();
}