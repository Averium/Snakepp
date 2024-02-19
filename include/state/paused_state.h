#pragma once

#include "game_state.h"


class PausedState : public GameState {

public:
    PausedState(Game* game);
    GameStateId conditions(void) const override;
};
