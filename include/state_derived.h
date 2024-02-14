#include "game.h"


/* STARTUP */

class StartupState : public State {

public:
    StartupState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* MENU */

class MenuState : public State {

public:
    MenuState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* SETTINGS */

class SettingsState : public State {

public:
    SettingsState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* KEYBIND */

class KeyBindsState : public State {

public:
    KeyBindsState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* HIGHSCORES */

class HighScoresState : public State {

public:
    HighScoresState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* GAME */

class GameState : public State {

public:
    GameState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* PAUSED */

class PausedState : public State {

public:
    PausedState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* GAMEOVER */

class GameOverState : public State {

public:
    GameOverState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};


/* SHUTDOWN */


class ShutdownState : public State {

public:
    ShutdownState(StateMachine* state_machine);
    GameStateId conditions(void) const override;

    void events(void);
    void update(void);
    void render(void);

};

