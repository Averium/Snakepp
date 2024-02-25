#pragma once

#include <map>
#include "state.h"

#include "gameover_state.h"
#include "highscores_state.h"
#include "keybind_state.h"
#include "menu_state.h"
#include "paused_state.h"
#include "running_state.h"
#include "settings_state.h"
#include "shutdown_state.h"
#include "startup_state.h"


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