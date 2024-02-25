#include "highscores_state.h"
#include "game.h"


HighScoresState::HighScoresState(Game* game) : GameState(HIGHSCORES, game) {}

GameStateId HighScoresState::conditions(void) const {
    if (game->highscores_back_button->is_clicked()) { return MENU; }
    return HIGHSCORES;
}


void HighScoresState::on_entry(void) {
    game->gui->activate_item(game->highscores_group);
}


void HighScoresState::on_exit(void) {
    game->gui->deactivate_item(game->highscores_group);
}