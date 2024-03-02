#include "gameover_state.hpp"
#include "game.hpp"


GameOverState::GameOverState(Game* game) : GameState(GAMEOVER, game) {}

GameStateId GameOverState::conditions(void) const {
    if (game->key_handler.check(KEY_R, PRESS)) { return GAME; }
    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return SHUTDOWN; }
    if (game->gameover_restart_button->is_clicked()) { return GAME; }
    if (game->gameover_menu_button->is_clicked()) { return MENU; }
    
    return GAMEOVER;
}


void GameOverState::on_entry(void) {
    game->gui->activate_item(game->gameover_group);
}


void GameOverState::on_exit(void) {
    game->gui->deactivate_item(game->gameover_group);
    game->reset();
}


void GameOverState::render(void) {
    game->grid.render_cells(game->snake.direction);
}