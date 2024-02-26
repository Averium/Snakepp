#include "game.h"
#include "debug.h"


Game::Game() {

    init_events();
    init_gui();
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
    init(new StartupState(this));
    add_state(new MenuState(this));
    add_state(new SettingsState(this));
    add_state(new KeyBindsState(this));
    add_state(new HighScoresState(this));
    add_state(new PausedState(this));
    add_state(new RunningState(this));
    add_state(new GameOverState(this));
    add_state(new ShutdownState(this));
}


void Game::init_events(void) {
    key_handler.add_key(KEY_UP);
    key_handler.add_key(KEY_DOWN);
    key_handler.add_key(KEY_LEFT);
    key_handler.add_key(KEY_RIGHT);
    key_handler.add_key(KEY_P);
    key_handler.add_key(KEY_R);
    key_handler.add_key(KEY_ESCAPE);
}


void Game::init_gui(void) {
    gui = new Gui();
    menu_group = new WidgetGroup(gui, 1);
    paused_group = new WidgetGroup(gui, 2);
    gameover_group = new WidgetGroup(gui, 3);
    settings_group = new WidgetGroup(gui, 4);
    keybinds_group = new WidgetGroup(gui, 5);
    highscores_group = new WidgetGroup(gui, 6);

    menu_start_button = new Button(menu_group, LAYOUT::MENU_START_BUTTON, "Start game", red_widget, CENTER, 1);
    menu_settings_button = new Button(menu_group, LAYOUT::MENU_SETTINGS_BUTTON, "Settings", grey_widget, CENTER, 2);
    menu_keybinds_button = new Button(menu_group, LAYOUT::MENU_KEYBINDS_BUTTON, "Keybinds", grey_widget, CENTER, 3);
    menu_highscores_button = new Button(menu_group, LAYOUT::MENU_HIGHSCORES_BUTTON, "High scores", grey_widget, CENTER, 4);
    menu_exit_button = new Button(menu_group, LAYOUT::MENU_EXIT_BUTTON, "Exit", red_widget, CENTER, 5);

    settings_back_button = new Button(settings_group, LAYOUT::MENU_BACK_BUTTON, "Back", grey_widget, CENTER, 1);
    settings_test_switch = new Switch(settings_group, LAYOUT::SETTINGS_TEST_SWITCH, "Switch", red_widget, false, CENTER, 2);

    keybinds_back_button = new Button(keybinds_group, LAYOUT::MENU_BACK_BUTTON, "Back", grey_widget, CENTER);
    highscores_back_button = new Button(highscores_group, LAYOUT::MENU_BACK_BUTTON, "Back", grey_widget, CENTER);

    paused_paused_label = new TextLabel(paused_group, LAYOUT::GRID_CENTER, "Paused", grey_widget, CENTER, 1);
    paused_info_label = new TextLabel(paused_group, LAYOUT::GAMEOVER_INFO, "Press 'p' to continue", grey_widget_small, CENTER, 2);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT::GAMEOVER_LABEL, "Game over", red_widget, CENTER, 1);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT::GAMEOVER_INFO, "Press 'r' to restart", grey_widget_small, CENTER, 2);
}


void Game::start(void) {
    reset();
    if (!running) {
        running = true;
        loop();
    }
}


void Game::stop(void) {
    running = false;
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
    grid.render_background();
    current_state->render();
    gui->render();
    EndDrawing();
}


void Game::loop(void) {
    while (running == true) {
        events();
        update();
        render();
    }
}