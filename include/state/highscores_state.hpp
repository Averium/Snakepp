#pragma once

#include "gui_state.hpp"


class HighScoresState : public GuiState {

public:
    HighScoresState(Game* game);
    GameStateId conditions(void) const override;
};
