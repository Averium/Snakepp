#include "gameover_state.hpp"
#include "game.hpp"


GameOverState::GameOverState(Game* game) : GameState(GAMEOVER_STATE, game) {}

GameStateId GameOverState::conditions(void) const {
    if (game->keyboard.check("Reset", PRESS)) { return GAME_STATE; }
    if (game->keyboard.check("Exit", PRESS)) { return SHUTDOWN_STATE; }
    if (game->gameover_restart_button->is_clicked()) { return GAME_STATE; }
    if (game->gameover_menu_button->is_clicked()) { return MENU_STATE; }
    
    return GAMEOVER_STATE;
}


void GameOverState::on_entry(void) {
    game->gui->activate_item(game->gameover_group);
}


void GameOverState::on_exit(void) {
    game->gui->deactivate_item(game->gameover_group);
    game->reset();
}


void GameOverState::render(void) const {
    game->grid.render_cells(game->snake.direction);
}