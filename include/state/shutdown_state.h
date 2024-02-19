#pragma once

#include "game_state.h"


class ShutdownState : public GameState {

public:
    ShutdownState(Game* game);
    GameStateId conditions(void) const override;
};
