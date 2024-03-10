#pragma once

#include "gui_state.hpp"


class SettingsState : public GuiState {

public:
    SettingsState(Game* game);
    GameStateId conditions(void) const override;

    void on_exit(void);
};
