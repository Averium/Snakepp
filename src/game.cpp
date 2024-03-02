#include "game.hpp"
#include "debug.hpp"


Game::Game() {

    init_window();
    init_events();
    init_gui();
    init_objects();
    init_states();

    running = false;
}


void Game::init_window(void) {
    InitWindow(LAYOUT("WINDOW").x, LAYOUT("WINDOW").y, "");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(SETTINGS("FPS"));
}


void Game::init_objects(void) {
    grid = Grid(LAYOUT("GRID"));
    logic_timer = Timer((float)(SETTINGS("GAME_PERIOD")) / 1000.0F);
    snake = Snake(Vector(5U, 1U), &grid);
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

    window_header = new WindowHeader(gui, LAYOUT("HEADER"), "Snake", STYLE_HEADER, 7);
    gui->activate_item(window_header);

    menu_start_button = new Button(menu_group, LAYOUT("MENU_ITEM_1"), "Start game", STYLE_RED_42, CENTER, 1);
    menu_settings_button = new Button(menu_group, LAYOUT("MENU_ITEM_2"), "Settings", STYLE_LIGHT_42, CENTER, 2);
    menu_keybinds_button = new Button(menu_group, LAYOUT("MENU_ITEM_3"), "Keybinds", STYLE_LIGHT_42, CENTER, 3);
    menu_highscores_button = new Button(menu_group, LAYOUT("MENU_ITEM_4"), "High scores", STYLE_LIGHT_42, CENTER, 4);
    menu_exit_button = new Button(menu_group, LAYOUT("MENU_ITEM_6"), "Exit", STYLE_RED_42, CENTER, 5);

    settings_back_button = new Button(settings_group, LAYOUT("MENU_ITEM_6"), "Back", STYLE_LIGHT_42, CENTER, 1);
    settings_test_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_2"), "Switch", STYLE_RED_42, false, CENTER, 2);
    settings_test_slider = new Slider(settings_group, LAYOUT("MENU_ITEM_3"), 200U, STYLE_RED_42, CENTER, 3);
    settings_test_label = new DataLabel<int>(settings_group, LAYOUT("MENU_ITEM_4"), "Test value", 0, STYLE_RED_STATIC_42, CENTER, 4);

    keybinds_back_button = new Button(keybinds_group, LAYOUT("MENU_ITEM_6"), "Back", STYLE_LIGHT_42, CENTER);
    highscores_back_button = new Button(highscores_group, LAYOUT("MENU_ITEM_6"), "Back", STYLE_LIGHT_42, CENTER);

    paused_paused_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_MAIN"), "Paused", STYLE_DARK_42, CENTER, 1);
    paused_info_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_SUB"), "Press 'p' to continue", STYLE_DARK_32, CENTER, 2);
    paused_resume_button = new Button(paused_group, LAYOUT("MENU_ITEM_1"), "Resume", STYLE_RED_42, CENTER, 3);
    paused_menu_button = new Button(paused_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42, CENTER, 4);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_MAIN"), "Game over", STYLE_RED_42, CENTER, 1);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_SUB"), "Press 'r' to restart", STYLE_DARK_32, CENTER, 2);
    gameover_restart_button = new Button(gameover_group, LAYOUT("MENU_ITEM_1"), "Restart", STYLE_RED_42, CENTER, 3);
    gameover_menu_button = new Button(gameover_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42, CENTER, 4);
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
    grid = Grid(LAYOUT("GRID"));
    snake = Snake(Vector(5U, 1U), &grid);
    apple.repos(&grid);
}


void Game::events(void) {
    key_handler.update();
    mouse_handler.update();

    gui->events(mouse_handler, key_handler);

    settings_test_label->set_value(settings_test_slider->map_value<int>(0, 10));

    if (window_header->is_close_clicked()) { stop(); }
    if (window_header->is_minimize_clicked()) { MinimizeWindow(); }

    current_state->events();
}


void Game::update(void) {
    check_for_transition();
    current_state->update();
}


void Game::render(void) {
    
    BeginDrawing();
    ClearBackground(COLORS("BACKGROUND"));

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