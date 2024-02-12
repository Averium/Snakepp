#include "game.h"
#include "debug.h"


Game::Game() {

    key_handler.add_key(KEY_UP);
    key_handler.add_key(KEY_DOWN);
    key_handler.add_key(KEY_LEFT);
    key_handler.add_key(KEY_RIGHT);
    key_handler.add_key(KEY_P);
    key_handler.add_key(KEY_R);

    mouse_handler.add_key(MOUSE_BUTTON_LEFT);

    grid = Grid(LAYOUT::GRID);
    logic_timer = Timer(GAME_PERIOD);

    snake = Snake(START_POS, &grid);
    apple.repos(&grid);

    running = false;
    paused = false;
    game_over = false;
}


void Game::events(void) {
    key_handler.update();
    mouse_handler.update();

    if (!paused) {
        if (key_handler.check(KEY_UP, PRESS)) { snake.turn(DIRECTION::UP); }
        if (key_handler.check(KEY_DOWN, PRESS)) { snake.turn(DIRECTION::DOWN); }
        if (key_handler.check(KEY_LEFT, PRESS)) { snake.turn(DIRECTION::LEFT); }
        if (key_handler.check(KEY_RIGHT, PRESS)) { snake.turn(DIRECTION::RIGHT); }
    }
    if (key_handler.check(KEY_P, PRESS)) { paused = !paused; }
    if (key_handler.check(KEY_R, PRESS)) { reset(); }
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
        
        snake_head->set_state(SNAKE_NEW, snake.length);
        
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
        snake = Snake(START_POS, &grid);
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

    grid.render(snake.direction);

    EndDrawing();
}