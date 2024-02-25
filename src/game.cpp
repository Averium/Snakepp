#include "game.h"
#include "debug.h"


Game::Game() {

    init_events();
    init_objects();
    init_states();
    init_gui();

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


void Game::init_gui(void) {
    gui = new Gui();
    paused_group = new WidgetGroup(gui, 1);
    gameover_group = new WidgetGroup(gui, 1);

    paused_label = new TextLabel(paused_group, Vector(60, 60), "PAUSED");
    gameover_label = new TextLabel(gameover_group, Vector(60, 60), "GAME OVER");
}


void Game::start(void) {
    reset();
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
    header.events(mouse_handler);
    gui->events(mouse_handler, key_handler);
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
    
    gui->render();

    EndDrawing();
}


void Game::loop(void) {
    while (running == true && WindowShouldClose() == false) {
        events();
        update();
        render();
    }
}