#include "highscores_state.hpp"
#include "game.hpp"


HighScoresState::HighScoresState(Game* game) : GameState(HIGHSCORES_STATE, game) {}

GameStateId HighScoresState::conditions(void) const {
    if (game->highscores_back_button->is_clicked()) { return MENU_STATE; }
    return HIGHSCORES_STATE;
}


void HighScoresState::on_entry(void) {
    game->gui->activate_item(game->highscores_group);
}


void HighScoresState::on_exit(void) {
    game->gui->deactivate_item(game->highscores_group);
}