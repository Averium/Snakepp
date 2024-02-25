#include "paused_state.h"
#include "game.h"


PausedState::PausedState(Game* game) : GameState(PAUSED, game) {}


GameStateId PausedState::conditions(void) const {
    if (game->key_handler.check(KEY_P, PRESS)) { return GAME; }
    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return SHUTDOWN; }
    return PAUSED;
}


void PausedState::render(void) {
    game->grid.render_cells(game->snake.direction);
}


void PausedState::on_entry(void) {
    game->gui->activate_item(game->paused_group);
}


void PausedState::on_exit(void) {
    game->gui->deactivate_item(game->paused_group);
}