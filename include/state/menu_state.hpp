#pragma once

#include "gui_state.hpp"


class MenuState : public GuiState {

public:
    MenuState(Game* game);
    GameStateId conditions(void) const override;
};
