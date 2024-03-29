#pragma once

#include "game_state.hpp"


class PausedState : public GameState {

public:
    PausedState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void) override;
    void on_exit(void) override;

    void render(ColorData& colors) const override;
};
