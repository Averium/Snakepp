#pragma once

#include "game_state.hpp"


class StartupState : public GameState {

public:
    StartupState(Game* game);
    GameStateId conditions(void) const override;
};
