#include "game.h"
#include "debug.h"


Game::Game() {
    grid = Grid();

    running = false;
    paused = false;
}


void Game::events(void) {

}


void Game::update(void) {

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