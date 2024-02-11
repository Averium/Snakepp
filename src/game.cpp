#include "game.h"
#include "debug.h"


Game::Game() {
    event_handler.add_key(KEY_W);
    event_handler.add_key(KEY_S);
    event_handler.add_key(KEY_A);
    event_handler.add_key(KEY_D);

    logic_timer = Timer(GAME_PERIOD);

    grid = Grid();
    snake = Snake(0U, 0U);

    running = false;
    paused = false;
}


void Game::events(void) {
    event_handler.update();
    if (event_handler.check(KEY_W, HOLD)) {snake.turn(DIRECTION::UP);}
    if (event_handler.check(KEY_S, HOLD)) {snake.turn(DIRECTION::DOWN);}
    if (event_handler.check(KEY_A, HOLD)) {snake.turn(DIRECTION::LEFT);}
    if (event_handler.check(KEY_D, HOLD)) {snake.turn(DIRECTION::RIGHT);}
}


void Game::update(void) {
    if (logic_timer.tick()) {
        snake.move();
        Cell* snake_head = grid.cell_at(snake.position);
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