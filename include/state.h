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

    inline virtual void events(void) {};
    inline virtual void update(void) {};
    inline virtual void render(void) {};

    const GameStateId id;

private:
    StateMachine* state_machine;

};


/* GAME STATE DECLARATIONS */

class StartupState : public State {

public:
    StartupState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class MenuState : public State {

public:
    MenuState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class SettingsState : public State {

public:
    SettingsState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class KeyBindsState : public State {

public:
    KeyBindsState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class HighScoresState : public State {

public:
    HighScoresState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class GameState : public State {

public:
    GameState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class PausedState : public State {

public:
    PausedState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class GameOverState : public State {

public:
    GameOverState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

class ShutdownState : public State {

public:
    ShutdownState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
    void render(void) override;

};

