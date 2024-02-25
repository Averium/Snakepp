#pragma once

#include "game_state.h"


class GameOverState : public GameState {

public:
    GameOverState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void) override;
    void on_exit(void) override;

    void render(void) override;
};
