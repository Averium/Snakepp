#pragma once

#include "game_state.hpp"


class BeginState : public GameState {

public:
    BeginState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void) override;
    void on_exit(void) override;

    void render(void) const override;
};
