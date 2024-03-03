#include "running_state.hpp"
#include "game.hpp"


RunningState::RunningState(Game* game) : GameState(GAME_STATE, game) {}


GameStateId RunningState::conditions(void) const {
    Cell* snake_head = game->grid.cell_at(game->snake.position);
    if (game->snake.dead) { return GAMEOVER_STATE; }
    if (game->key_handler.check(KEY_P, PRESS)) { return PAUSED_STATE; }
    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return PAUSED_STATE; }

    return GAME_STATE;
}


void RunningState::events(void) {
    if (game->key_handler.check(KEY_W, PRESS)) { game->snake.turn(DIRECTION::UP); }
    if (game->key_handler.check(KEY_S, PRESS)) { game->snake.turn(DIRECTION::DOWN); }
    if (game->key_handler.check(KEY_A, PRESS)) { game->snake.turn(DIRECTION::LEFT); }
    if (game->key_handler.check(KEY_D, PRESS)) { game->snake.turn(DIRECTION::RIGHT); }
}


void RunningState::update(void) {
    if (game->snake.ready_to_move()) {
        
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