#pragma once

#include "gui_state.hpp"


class AboutState : public GuiState {

public:
    AboutState(Game* game);
    GameStateId conditions(void) const override;
};
