#pragma once

#include "game_state.hpp"


class HighScoresState : public GameState {

public:
    HighScoresState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void);
    void on_exit(void);
};
