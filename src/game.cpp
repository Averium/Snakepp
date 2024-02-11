#include "game.h"
#include "debug.h"


Game::Game() {
    event_handler.add_key(KEY_W);
    event_handler.add_key(KEY_S);
    event_handler.add_key(KEY_A);
    event_handler.add_key(KEY_D);
    event_handler.add_key(KEY_P);

    logic_timer = Timer(GAME_PERIOD);

    snake = Snake(UINT_ZERO, UINT_ZERO);
    apple.repos(&grid);

    running = false;
    paused = false;
}


void Game::events(void) {
    event_handler.update();

    if (event_handler.check(KEY_W, PRESS)) { snake.turn(DIRECTION::UP); }
    if (event_handler.check(KEY_S, PRESS)) { snake.turn(DIRECTION::DOWN); }
    if (event_handler.check(KEY_A, PRESS)) { snake.turn(DIRECTION::LEFT); }
    if (event_handler.check(KEY_D, PRESS)) { snake.turn(DIRECTION::RIGHT); }

    if (event_handler.check(KEY_P, PRESS)) { paused = !paused; }
}


void Game::update(void) {
    if (!paused && logic_timer.tick()) {
        
        snake.change_direction();
        snake.move();
        
        Cell* snake_head = grid.cell_at(snake.position);
        
        if (snake_head->type == SNAKE_BODY) {
            // GAME OVER
        }
        else if (snake_head->type == APPLE) {
            snake.length++;
            apple.repos(&grid);
        }
        
        snake_head->set_state(SNAKE_HEAD, snake.length);
        
        grid.update();
    }
}


void Game::start(void) {
    running = true;
    paused = false;

    loop();
}


void Game::loop(void) {

    while (running == true && WindowShouldClose() == false) {
        events();
        update();
        render();
    }
}


void Game::render(void) {
    BeginDrawing();
    ClearBackground(COLORS::BACKGROUND);

    grid.render();

    EndDrawing();
}