#pragma once

#include <map>
#include "state.h"


class StateMachine {

public:
    StateMachine(void);
    ~StateMachine(void);

    void add_state(State* state);

    void transition(void);

    virtual void events(void);
    virtual void update(void);
    virtual void render(void);

private:
    std::map<GameStateId, State*> states;
    State* current_state = nullptr;

};