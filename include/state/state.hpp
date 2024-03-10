#pragma once


enum GameStateId {
    STARTUP_STATE,
    MENU_STATE,
    SETTINGS_STATE,
    KEYBINDS_STATE,
    HIGHSCORES_STATE,
    BEGIN_STATE,
    GAME_STATE,
    PAUSED_STATE,
    GAMEOVER_STATE,
    NEWHIGHSCORE_STATE,
    SHUTDOWN_STATE,
    ABOUT_STATE,
};


class StateMachine;


class State {

public:
    inline State(GameStateId id, StateMachine* state_machine): id(id), state_machine(state_machine) {};

    inline virtual GameStateId conditions(void) const = 0;

    inline virtual void on_entry(void) {}
    inline virtual void on_exit(void) {}

    virtual void events(void) = 0;
    virtual void update(void) = 0;
    virtual void render(void) const = 0;

    const GameStateId id;

protected:
    StateMachine* state_machine;

};
