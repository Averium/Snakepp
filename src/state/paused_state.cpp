#include "paused_state.h"
#include "game.h"


PausedState::PausedState(Game* game) : GameState(PAUSED, game) {}

GameStateId PausedState::conditions(void) const {
    if (game->key_handler.check(KEY_P, PRESS)) { return GAME; }
    return PAUSED;
}