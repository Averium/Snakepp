#include "state.h"
#include "state_machine.h"

State::State(GameStateId id, StateMachine* state_machine): id(id), state_machine(state_machine) {}

GameStateId State::conditions(void) const {
    return id;
}