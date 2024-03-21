#include "paused_state.hpp"
#include "game.hpp"


PausedState::PausedState(Game* game) : GameState(PAUSED_STATE, game) {}


GameStateId PausedState::conditions(void) const {
    if (game->keyboard.check("Pause", PRESS)) { return GAME_STATE; }
    if (game->keyboard.check("Exit", PRESS)) { return MENU_STATE; }
    if (game->paused_resume_button->is_clicked()) { return BEGIN_STATE; }
    if (game->paused_menu_button->is_clicked()) { return MENU_STATE; }
    return PAUSED_STATE;
}


void PausedState::on_entry(void) {
    game->gui->activate_item(game->paused_group);
}


void PausedState::on_exit(void) {
    game->gui->deactivate_item(game->paused_group);
}


void PausedState::render(ColorData& colors) const {
    game->grid.render_cells(colors, game->snake.direction, true);
}