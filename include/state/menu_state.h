#pragma once

#include "game_state.h"


class MenuState : public GameState {

public:
    MenuState(Game* game);
    GameStateId conditions(void) const override;
};
