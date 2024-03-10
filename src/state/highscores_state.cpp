#include "highscores_state.hpp"
#include "game.hpp"


HighScoresState::HighScoresState(
    Game* game
) :
    GuiState(HIGHSCORES_STATE, game, game->highscores_group) {}

GameStateId HighScoresState::conditions(void) const {
    if (game->highscores_back_button->is_clicked()) { return MENU_STATE; }
    return HIGHSCORES_STATE;
}