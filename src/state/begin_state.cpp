#pragma once

#include "begin_state.hpp"
#include "game.hpp"


BeginState::BeginState(Game* game) : GameState(BEGIN_STATE, game) {}


GameStateId BeginState::conditions(void) const {
    if (game->keyboard.wait_for_key() != KEY_NULL) { return GAME_STATE; }
    return BEGIN_STATE;
}


void BeginState::render(void) const {
    game->grid.render_cells(game->snake.direction);
}