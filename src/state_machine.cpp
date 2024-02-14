#include "state_machine.h"


StateMachine::StateMachine(void) {}

StateMachine::~StateMachine() {
    for (std::pair<const GameStateId, State*>& pair : states) {
        delete pair.second;
    }
}


void StateMachine::add_state(State* state) {
    states[state->id] = state;

    if (current_state == nullptr) {
        current_state = state;
        current_state->on_entry();
    }
}


void StateMachine::transition(void) {
    GameStateId next_state_id = current_state->conditions();

    if (next_state_id != current_state->id) {
        current_state->on_exit();
        current_state = states[next_state_id];
        current_state->on_entry();
    }
}


void StateMachine::events(void) { current_state->events(); }
void StateMachine::update(void) { current_state->update(); }
void StateMachine::render(void) { current_state->render(); }
