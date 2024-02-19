#include "game.h"
#include "debug.h"


Game::Game() {

    init_events();
    init_objects();
    init_states();

    running = false;
}


void Game::init_objects(void) {
    header = WindowHeader(LAYOUT::HEADER, CONST::HEADER_TEXT);
    grid = Grid(LAYOUT::GRID);
    logic_timer = Timer(CONST::GAME_PERIOD);
    snake = Snake(START_POS, &grid);
    apple.repos(&grid);
}


void Game::init_states(void) {
    init(new PausedState(this));
    add_state(new RunningState(this));
    add_state(new GameOverState(this));
}


void Game::init_events(void) {
    key_handler.add_key(KEY_UP);
    key_handler.add_key(KEY_DOWN);
    key_handler.add_key(KEY_LEFT);
    key_handler.add_key(KEY_RIGHT);
    key_handler.add_key(KEY_P);
    key_handler.add_key(KEY_R);
}


void Game::start(void) {
    if (!running) {
        running = true;
        loop();
    }
}


void Game::reset(void) {
    grid = Grid(LAYOUT::GRID);
    snake = Snake(START_POS, &grid);
    apple.repos(&grid);
}


void Game::events(void) {
    key_handler.update();
    mouse_handler.update();
    header.events(&mouse_handler);
    current_state->events();
}


void Game::update(void) {
    check_for_transition();
    current_state->update();
}


void Game::render(void) {
    BeginDrawing();
    ClearBackground(COLORS::BACKGROUND);

    header.render();
    grid.render(snake.direction);

    current_state->render();

    EndDrawing();
}


void Game::loop(void) {

    while (running == true && WindowShouldClose() == false) {
        events();
        update();
        render();
    }
}