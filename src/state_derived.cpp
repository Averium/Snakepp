#include "state_derived.h"
#include "state_machine.h"


/* STARTUP */

StartupState::StartupState(StateMachine* state_machine) : State(STARTUP, state_machine) {}

GameStateId StartupState::conditions(void) const {
    return STARTUP;
}

void StartupState::events(void) {}
void StartupState::update(void) {}
void StartupState::render(void) {}


/* MENU */

MenuState::MenuState(StateMachine* state_machine) : State(MENU, state_machine) {}

GameStateId MenuState::conditions(void) const {
    return MENU;
}

void MenuState::events(void) {}
void MenuState::update(void) {}
void MenuState::render(void) {}


/* SETTINGS */

SettingsState::SettingsState(StateMachine* state_machine) : State(SETTINGS, state_machine) {}

GameStateId SettingsState::conditions(void) const {
    return SETTINGS;
}

void SettingsState::events(void) {}
void SettingsState::update(void) {}
void SettingsState::render(void) {}


/* KEYBINDS */

KeyBindsState::KeyBindsState(StateMachine* state_machine) : State(KEYBINDS, state_machine) {}

GameStateId KeyBindsState::conditions(void) const {
    return KEYBINDS;
}

void KeyBindsState::events(void) {}
void KeyBindsState::update(void) {}
void KeyBindsState::render(void) {}


/* HIGHSCORES */

HighScoresState::HighScoresState(StateMachine* state_machine) : State(HIGHSCORES, state_machine) {}

GameStateId HighScoresState::conditions(void) const {
    return HIGHSCORES;
}

void HighScoresState::events(void) {}
void HighScoresState::update(void) {}
void HighScoresState::render(void) {}


/* GAME */

GameState::GameState(StateMachine* state_machine) : State(GAME, state_machine) {}

GameStateId GameState::conditions(void) const {
    return GAME;
}

void GameState::events(void) {}
void GameState::update(void) {}
void GameState::render(void) {}


/* PAUSED */

PausedState::PausedState(StateMachine* state_machine) : State(PAUSED, state_machine) {}

GameStateId PausedState::conditions(void) const {
    return PAUSED;
}

void PausedState::events(void) {}
void PausedState::update(void) {}
void PausedState::render(void) {}


/* GAMEOVER */

GameOverState::GameOverState(StateMachine* state_machine) : State(GAMEOVER, state_machine) {}

GameStateId GameOverState::conditions(void) const {
    return GAMEOVER;
}

void GameOverState::events(void) {}
void GameOverState::update(void) {}
void GameOverState::render(void) {}


/* SHUTDOWN */

ShutdownState::ShutdownState(StateMachine* state_machine) : State(SHUTDOWN, state_machine) {}

GameStateId ShutdownState::conditions(void) const {
    return SHUTDOWN;
}

void ShutdownState::events(void) {}
void ShutdownState::update(void) {}
void ShutdownState::render(void) {}

