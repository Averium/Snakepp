#include "paused_state.hpp"
#include "game.hpp"


PausedState::PausedState(Game* game) : GameState(PAUSED_STATE, game) {}


GameStateId PausedState::conditions(void) const {
    if (game->key_handler.check(KEY_P, PRESS)) { return GAME_STATE; }
    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return MENU_STATE; }
    
    if (game->paused_resume_button->is_clicked()) { return GAME_STATE; }
    if (game->paused_menu_button->is_clicked()) { return MENU_STATE; }
    return PAUSED_STATE;
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