#pragma once

#include <map>
#include "state.h"


class StateMachine {

public:
    StateMachine(void);
    ~StateMachine(void);

    void add_state(State* state);
    void init(State* state);
    void reset(void);
    void update_state(void);

private:

    void activate_state(State* state);

    std::map<GameStateId, State*> states;
    State* current_state = nullptr;
    State* init_state = nullptr;

};