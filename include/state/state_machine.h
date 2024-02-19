#pragma once

#include <map>
#include "state.h"


class StateMachine {

public:
    StateMachine(void);
    ~StateMachine();

    void add_state(State* state);
    void init(State* state);
    void reset(void);
    void check_for_transition(void);

private:
    void activate_state(State* state);

    std::map<GameStateId, State*> states;
    State* init_state = nullptr;

protected:
    State* current_state = nullptr;

};