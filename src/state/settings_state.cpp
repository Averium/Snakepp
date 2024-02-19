#include "settings_state.h"
#include "game.h"


SettingsState::SettingsState(Game* game) : GameState(SETTINGS, game) {}

GameStateId SettingsState::conditions(void) const {
    return SETTINGS;
}