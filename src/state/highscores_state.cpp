#include "highscores_state.h"
#include "game.h"


HighScoresState::HighScoresState(Game* game) : GameState(HIGHSCORES, game) {}

GameStateId HighScoresState::conditions(void) const {
    return HIGHSCORES;
}