#pragma once

#include "game_state.hpp"
#include "widget_group.hpp"


class GuiState : public GameState {

public:
    GuiState(GameStateId id, Game* game, WidgetGroup* widget_group);

    virtual void on_entry(void) override;
    virtual void on_exit(void) override; 

protected:
    WidgetGroup* widget_group;
};