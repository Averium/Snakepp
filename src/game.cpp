#include "game.h"
#include "debug.h"


Game::Game() {
    event_handler.add_key(KEY_W);
    event_handler.add_key(KEY_S);
    event_handler.add_key(KEY_A);
    event_handler.add_key(KEY_D);
    event_handler.add_key(KEY_P);
    event_handler.add_key(KEY_R);

    grid = Grid(LAYOUT::GRID);
    logic_timer = Timer(GAME_PERIOD);

    snake = Snake(UINT_ZERO, UINT_ZERO);
    apple.repos(&grid);

    running = false;
    paused = false;
    game_over = false;
}


void Game::events(void) {
    event_handler.update();

    if (event_handler.check(KEY_W, PRESS)) { snake.turn(DIRECTION::UP); }
    if (event_handler.check(KEY_S, PRESS)) { snake.turn(DIRECTION::DOWN); }
    if (event_handler.check(KEY_A, PRESS)) { snake.turn(DIRECTION::LEFT); }
    if (event_handler.check(KEY_D, PRESS)) { snake.turn(DIRECTION::RIGHT); }

    if (event_handler.check(KEY_P, PRESS)) { paused = !paused; }
    if (event_handler.check(KEY_R, PRESS)) { reset(); }
}


void Game::update(void) {
    if (!paused && !game_over && logic_timer.tick()) {
        
        snake.change_direction();
        snake.move();
        
        Cell* snake_head = grid.cell_at(snake.position);
        
        if (snake_head->type == SNAKE_BODY) {
            game_over = true;
        }
        else if (snake_head->type == APPLE) {
            snake.length++;
            apple.repos(&grid);
        }
        
        snake_head->set_state(SNAKE_BODY, snake.length);
        
        grid.update();
    }
}


void Game::start(void) {
    if (!running) {
        running = true;
        paused = true;
        loop();
    }
}


void Game::reset(void) {
    if (game_over) {
        paused = true;
        game_over = false;

        grid = Grid(LAYOUT::GRID);
        snake = Snake(UINT_ZERO, UINT_ZERO);
        apple.repos(&grid);
    }
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