#pragma once

#include "game_state.hpp"


class NewHighscoreState : public GameState {

public:
    NewHighscoreState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void) override;
    void on_exit(void) override;
};