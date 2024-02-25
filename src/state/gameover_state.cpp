#include "gameover_state.h"
#include "game.h"


GameOverState::GameOverState(Game* game) : GameState(GAMEOVER, game) {}

GameStateId GameOverState::conditions(void) const {
    if (game->key_handler.check(KEY_R, PRESS)) { return GAME; }
    return GAMEOVER;
}


void GameOverState::on_entry(void) {
    game->gui->activate_item(game->gameover_group);
}


void GameOverState::on_exit(void) {
    game->gui->deactivate_item(game->gameover_group);
    game->reset();
}