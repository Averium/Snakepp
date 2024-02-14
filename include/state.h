#pragma once


enum GameStateId {
    STARTUP,
    MENU,
    SETTINGS,
    KEYBINDS,
    HIGHSCORES,
    GAME,
    PAUSED,
    GAMEOVER,
    SHUTDOWN,
};


class StateMachine;


class State {

public:
    State(GameStateId id, StateMachine* state_machine);

    virtual GameStateId conditions(void) const;

    inline virtual void on_entry(void) {};
    inline virtual void on_exit(void) {};

    const GameStateId id;

private:
    StateMachine* state_machine;

};
