#include "settings_state.hpp"
#include "game.hpp"


SettingsState::SettingsState(
    Game* game
) :
    GuiState(SETTINGS_STATE, game, game->settings_group)
{}

GameStateId SettingsState::conditions(void) const {
    if (game->settings_back_button->is_clicked()) { return MENU_STATE; }
    return SETTINGS_STATE;
}


void SettingsState::on_exit(void) {
    GuiState::on_exit();
    game->save_settings();
}
