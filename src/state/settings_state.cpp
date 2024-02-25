#include "settings_state.h"
#include "game.h"


SettingsState::SettingsState(Game* game) : GameState(SETTINGS, game) {}

GameStateId SettingsState::conditions(void) const {
    if (game->settings_back_button->is_clicked()) { return MENU; }
    return SETTINGS;
}


void SettingsState::on_entry(void) {
    game->gui->activate_item(game->settings_group);
}


void SettingsState::on_exit(void) {
    game->gui->deactivate_item(game->settings_group);
}
