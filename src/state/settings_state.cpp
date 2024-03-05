#include "settings_state.hpp"
#include "game.hpp"


SettingsState::SettingsState(Game* game) : GameState(SETTINGS_STATE, game) {}

GameStateId SettingsState::conditions(void) const {
    if (game->settings_back_button->is_clicked()) { return MENU_STATE; }
    return SETTINGS_STATE;
}


void SettingsState::on_entry(void) {
    game->gui->activate_item(game->settings_group);
}


void SettingsState::on_exit(void) {
    game->gui->deactivate_item(game->settings_group);
    game->save_settings();
}
