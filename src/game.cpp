#include "game.h"
#include "debug.h"


Game::Game() {
    grid = Grid();
    snake = Snake(0U, 0U);
    logic_timer = Timer(GAME_PERIOD);

    running = false;
    paused = false;
}


void Game::events(void) {

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