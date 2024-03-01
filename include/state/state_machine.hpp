#pragma once

#include <map>

#include "state.hpp"

#include "gameover_state.hpp"
#include "highscores_state.hpp"
#include "keybind_state.hpp"
#include "menu_state.hpp"
#include "paused_state.hpp"
#include "running_state.hpp"
#include "settings_state.hpp"
#include "shutdown_state.hpp"
#include "startup_state.hpp"


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