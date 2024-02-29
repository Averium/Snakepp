#pragma once

#include "game_state.hpp"


class ShutdownState : public GameState {

public:
    ShutdownState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void);
};
