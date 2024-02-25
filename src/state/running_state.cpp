#include "running_state.h"
#include "game.h"


RunningState::RunningState(Game* game) : GameState(GAME, game) {}


GameStateId RunningState::conditions(void) const {
    Cell* snake_head = game->grid.cell_at(game->snake.position);
    if (game->snake.dead) { return GAMEOVER; }
    if (game->key_handler.check(KEY_P, PRESS)) { return PAUSED; }
    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return PAUSED; }

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


void RunningState::render(void) {
    game->grid.render_cells(game->snake.direction);
}