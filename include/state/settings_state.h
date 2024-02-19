#pragma once

#include "game_state.h"


class SettingsState : public GameState {

public:
    SettingsState(Game* game);
    GameStateId conditions(void) const override;
};
