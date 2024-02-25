#include "startup_state.h"
#include "game.h"


StartupState::StartupState(Game* game) : GameState(STARTUP, game) {}

GameStateId StartupState::conditions(void) const {
    return MENU;
}