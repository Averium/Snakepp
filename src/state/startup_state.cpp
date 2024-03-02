#include "startup_state.hpp"
#include "game.hpp"


StartupState::StartupState(Game* game) : GameState(STARTUP_STATE, game) {}

GameStateId StartupState::conditions(void) const {
    return MENU_STATE;
}