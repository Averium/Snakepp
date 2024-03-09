#pragma once

#include "game_state.hpp"


class BeginState : public GameState {

public:
    BeginState(Game* game);
    GameStateId conditions(void) const override;

    void render(void) const override;
};
