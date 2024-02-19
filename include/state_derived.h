#pragma once

#include "state.h"
#include "debug.h"


class Game;


/* DERIVED GAME STATE */

class GameState: public State {

public:
    inline GameState(GameStateId id, Game* game) : State(id, nullptr), game(game) {}

    virtual void events(void) {};
    virtual void update(void) {};
    virtual void render(void) {};

protected:
    Game* game;

};


/* STARTUP */

class StartupState : public GameState {

public:
    StartupState(Game* game);
    GameStateId conditions(void) const override;
};


/* MENU */

class MenuState : public GameState {

public:
    MenuState(Game* game);
    GameStateId conditions(void) const override;
};


/* SETTINGS */

class SettingsState : public GameState {

public:
    SettingsState(Game* game);
    GameStateId conditions(void) const override;
};


/* KEYBIND */

class KeyBindsState : public GameState {

public:
    KeyBindsState(Game* game);
    GameStateId conditions(void) const override;
};


/* HIGHSCORES */

class HighScoresState : public GameState {

public:
    HighScoresState(Game* game);
    GameStateId conditions(void) const override;
};


/* GAME */

class RunningState : public GameState {

public:
    RunningState(Game* game);
    GameStateId conditions(void) const override;

    void events(void) override;
    void update(void) override;
};


/* PAUSED */

class PausedState : public GameState {

public:
    PausedState(Game* game);
    GameStateId conditions(void) const override;
};


/* GAMEOVER */

class GameOverState : public GameState {

public:
    GameOverState(Game* game);
    GameStateId conditions(void) const override;

    void on_exit(void) override;
};


/* SHUTDOWN */

class ShutdownState : public GameState {

public:
    ShutdownState(Game* game);
    GameStateId conditions(void) const override;
};
