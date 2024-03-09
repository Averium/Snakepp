#include "running_state.hpp"
#include "game.hpp"


RunningState::RunningState(Game* game) : GameState(GAME_STATE, game) {}


GameStateId RunningState::conditions(void) const {
    if (game->snake.is_dead()) {
        if (game->score.is_highscore()) { return NEWHIGHSCORE_STATE; }
        else { return GAMEOVER_STATE; }
    }
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
            game->snake.set_dead();
            return;
        }
        
        Cell& snake_head = game->grid.cell_at(game->snake.position);
        
        switch (snake_head.type) {
        case SNAKE_BODY:
            game->snake.set_dead();
            break;

        case APPLE:
            game->snake.increment_length();
            game->score.increment_apples();
            game->apple.repos(game->grid);

            if (game->randomizer.roll_bonus()) {
                game->bonus.repos(game->grid);
            }
            break;

        case BONUS:
            game->snake.increment_length();
            game->score.increment_bonuses();
            break;
        }
        
        snake_head.set_state(SNAKE_NEW, game->snake.get_length());
        
        game->grid.update();
    }
}


void RunningState::render(void) const {
    game->grid.render_cells(game->snake.direction);
}