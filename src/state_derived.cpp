#include "state_derived.h"
#include "game.h"


/* STARTUP */

StartupState::StartupState(Game* game) : GameState(STARTUP, game) {}

GameStateId StartupState::conditions(void) const {
    return STARTUP;
}


/* MENU */

MenuState::MenuState(Game* game) : GameState(MENU, game) {}

GameStateId MenuState::conditions(void) const {
    return MENU;
}


/* SETTINGS */

SettingsState::SettingsState(Game* game) : GameState(SETTINGS, game) {}

GameStateId SettingsState::conditions(void) const {
    return SETTINGS;
}


/* KEYBINDS */

KeyBindsState::KeyBindsState(Game* game) : GameState(KEYBINDS, game) {}

GameStateId KeyBindsState::conditions(void) const {
    return KEYBINDS;
}


/* HIGHSCORES */

HighScoresState::HighScoresState(Game* game) : GameState(HIGHSCORES, game) {}

GameStateId HighScoresState::conditions(void) const {
    return HIGHSCORES;
}


/* GAME */

RunningState::RunningState(Game* game) : GameState(GAME, game) {}

GameStateId RunningState::conditions(void) const {
    Cell* snake_head = game->grid.cell_at(game->snake.position);
    if (game->snake.dead) { return GAMEOVER; }
    if (game->key_handler.check(KEY_P, PRESS)) { return PAUSED; }
    return GAME;
}

void RunningState::events(void) {
    if (game->key_handler.check(KEY_UP, PRESS)) { game->snake.turn(DIRECTION::UP); }
    if (game->key_handler.check(KEY_DOWN, PRESS)) { game->snake.turn(DIRECTION::DOWN); }
    if (game->key_handler.check(KEY_LEFT, PRESS)) { game->snake.turn(DIRECTION::LEFT); }
    if (game->key_handler.check(KEY_RIGHT, PRESS)) { game->snake.turn(DIRECTION::RIGHT); }
}

void RunningState::update(void) {
    if (game->logic_timer.tick()) {
        
        game->snake.change_direction();
        game->snake.move();
        
        Cell* snake_head = game->grid.cell_at(game->snake.position);
        
        if (snake_head->type == SNAKE_BODY) {
            game->snake.dead = true;
        }

        if (snake_head->type == APPLE) {
            game->snake.length++;
            game->apple.repos(&game->grid);
        }
        
        snake_head->set_state(SNAKE_NEW, game->snake.length);
        
        game->grid.update();
    }
}


/* PAUSED */

PausedState::PausedState(Game* game) : GameState(PAUSED, game) {}

GameStateId PausedState::conditions(void) const {
    if (game->key_handler.check(KEY_P, PRESS)) { return GAME; }
    return PAUSED;
}


/* GAMEOVER */

GameOverState::GameOverState(Game* game) : GameState(GAMEOVER, game) {}

GameStateId GameOverState::conditions(void) const {
    if (game->key_handler.check(KEY_R, PRESS)) { return GAME; }
    return GAMEOVER;
}

void GameOverState::on_exit(void) {
    game->reset();
}


/* SHUTDOWN */

ShutdownState::ShutdownState(Game* game) : GameState(SHUTDOWN, game) {}

GameStateId ShutdownState::conditions(void) const {
    return SHUTDOWN;
}
