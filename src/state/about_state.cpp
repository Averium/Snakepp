#include "about_state.hpp"
#include "game.hpp"


AboutState::AboutState(
    Game* game
) :
    GuiState(ABOUT_STATE, game, game->about_group) {}

GameStateId AboutState::conditions(void) const {
    if (game->about_back_button->is_clicked()) { return MENU_STATE; }
    return ABOUT_STATE;
}