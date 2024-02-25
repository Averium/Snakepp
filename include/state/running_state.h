#pragma once

#include "game_state.h"


class RunningState : public GameState {

public:
    RunningState(Game* game);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;
};
