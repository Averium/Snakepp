#include "menu_state.h"
#include "game.h"


MenuState::MenuState(Game* game) : GameState(MENU, game) {}

GameStateId MenuState::conditions(void) const {
    return MENU;
}