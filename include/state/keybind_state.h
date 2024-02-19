#pragma once

#include "game_state.h"


class KeyBindsState : public GameState {

public:
    KeyBindsState(Game* game);
    GameStateId conditions(void) const override;
};
