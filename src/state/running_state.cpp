#include "running_state.hpp"
#include "game.hpp"


RunningState::RunningState(Game* game) : GameState(GAME_STATE, game) {}


GameStateId RunningState::conditions(void) const {
    Cell* snake_head = game->grid.cell_at(game->snake.position);
    if (game->snake.dead) { return GAMEOVER_STATE; }
    if (game->keyboard.check("Pause", PRESS)) { return PAUSED_STATE; }
    if (game->keyboard.check("Exit", PRESS)) { return PAUSED_STATE; }

    return GAME_STATE;
}


void RunningState::events(void) {
    if (game->keyboard.check("Up", PRESS)) { game->snake.turn(DIRECTION::UP); }
    if (game->keyboard.check("Down", PRESS)) { game->snake.turn(DIRECTION::DOWN); }
    if (game->keyboard.check("Left", PRESS)) { game->snake.turn(DIRECTION::LEFT); }
    if (game->keyboard.check("Right", PRESS)) { game->snake.turn(DIRECTION::RIGHT); }
}


void RunningState::update(void) {
    if (game->snake.ready_to_move()) {
        
        game->snake.change_direction();
        if (game->snake.move(game->SETTINGS("WALLS"))) {
            game->snake.dead = true;
            return;
        }
        
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