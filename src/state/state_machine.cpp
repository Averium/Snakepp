#include "state_machine.hpp"


StateMachine::StateMachine(void) {}

StateMachine::~StateMachine() {
    for (std::pair<const GameStateId, State*>& pair : states) {
        delete pair.second;
    }
}


void StateMachine::add_state(State* state) {
    states[state->id] = state;
}


void StateMachine::init(State* state) {
    init_state = state;
    add_state(state);
    activate_state(state);
}


void StateMachine::activate_state(State* state) {
    if (current_state != nullptr) {
        current_state->on_exit();
    }
    current_state = state;
    current_state->on_entry();
}


void StateMachine::reset(void) {
    activate_state(init_state);
}


void StateMachine::check_for_transition(void) {
    GameStateId next_state_id = current_state->conditions();

    if (next_state_id != current_state->id) {
        activate_state(states[next_state_id]);
    }
}
