#include "keybind_state.h"
#include "game.h"


KeyBindsState::KeyBindsState(Game* game) : GameState(KEYBINDS, game) {}

GameStateId KeyBindsState::conditions(void) const {
    return KEYBINDS;
}