#pragma once

#include "gui_state.hpp"


class KeyBindsState : public GuiState {

public:
    KeyBindsState(Game* game);
    GameStateId conditions(void) const override;

    void on_exit(void);
};
