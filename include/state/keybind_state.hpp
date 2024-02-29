#pragma once

#include "game_state.hpp"


class KeyBindsState : public GameState {

public:
    KeyBindsState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void);
    void on_exit(void);
};
