#include "shutdown_state.hpp"
#include "game.hpp"


ShutdownState::ShutdownState(Game* game) : GameState(SHUTDOWN_STATE, game) {}

GameStateId ShutdownState::conditions(void) const {
    return SHUTDOWN_STATE;
}


void ShutdownState::on_entry(void) {
    game->stop();
}