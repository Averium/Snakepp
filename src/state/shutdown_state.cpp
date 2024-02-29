#include "shutdown_state.hpp"
#include "game.hpp"


ShutdownState::ShutdownState(Game* game) : GameState(SHUTDOWN, game) {}

GameStateId ShutdownState::conditions(void) const {
    return SHUTDOWN;
}


void ShutdownState::on_entry(void) {
    game->stop();
}