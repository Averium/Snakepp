#pragma once

#include "game_state.hpp"


class SettingsState : public GameState {

public:
    SettingsState(Game* game);
    GameStateId conditions(void) const override;

    void on_entry(void);
    void on_exit(void);
};
