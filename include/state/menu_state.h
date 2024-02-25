#pragma once

#include "game_state.h"


class MenuState : public GameState {

public:
    MenuState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void) override;
    void on_exit(void) override;
};
