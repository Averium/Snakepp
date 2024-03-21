#include "begin_state.hpp"
#include "game.hpp"


BeginState::BeginState(Game* game) : GameState(BEGIN_STATE, game) {}


GameStateId BeginState::conditions(void) const {
    if (game->keyboard.wait_for_key() != KEY_NULL) { return GAME_STATE; }
    return BEGIN_STATE;
}


void BeginState::on_entry(void) {
    game->gui->activate_item(game->begin_group);
}


void BeginState::on_exit(void) {
    game->gui->deactivate_item(game->begin_group);
}


void BeginState::render(ColorData& colors) const {
    game->grid.render_cells(colors, game->snake.direction);
}