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
    inline State(GameStateId id, StateMachine* state_machine): id(id), state_machine(state_machine) {};

    inline virtual GameStateId conditions(void) const { return id; };

    inline virtual void on_entry(void) {}
    inline virtual void on_exit(void) {}

    virtual void events(void) = 0;
    virtual void update(void) = 0;
    virtual void render(void) = 0;

    const GameStateId id;

protected:
    StateMachine* state_machine;

};
