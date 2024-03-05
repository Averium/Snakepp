#include "game.hpp"
#include "debug.hpp"


Game::Game() {

    init_window();
    init_gui();
    init_objects();
    init_states();

    load_settings();

    running = false;
}


void Game::init_window(void) {
    InitWindow(LAYOUT("WINDOW").x, LAYOUT("WINDOW").y, "");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(SETTINGS("FPS"));
}


void Game::init_objects(void) {
    grid = Grid(LAYOUT("GRID"));

    int delay = settings_speed_slider->get("DELAY");
    snake = Snake(&grid, Vector(5U, 1U), delay, SETTINGS("SNAKE_STARTING_LENGTH"));

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


void Game::init_gui(void) {
    gui = new Gui();
    menu_group = new WidgetGroup(gui);
    paused_group = new WidgetGroup(gui);
    gameover_group = new WidgetGroup(gui);
    settings_group = new WidgetGroup(gui);
    keybinds_group = new WidgetGroup(gui);
    highscores_group = new WidgetGroup(gui);

    window_header = new WindowHeader(gui, LAYOUT("HEADER"), "Snake", STYLE_HEADER);
    gui->activate_item(window_header);

    menu_start_button = new Button(menu_group, LAYOUT("MENU_ITEM_1"), "Start game", STYLE_RED_42);
    menu_settings_button = new Button(menu_group, LAYOUT("MENU_ITEM_2"), "Settings", STYLE_LIGHT_42);
    menu_keybinds_button = new Button(menu_group, LAYOUT("MENU_ITEM_3"), "Keybinds", STYLE_LIGHT_42);
    menu_highscores_button = new Button(menu_group, LAYOUT("MENU_ITEM_4"), "High scores", STYLE_LIGHT_42);
    menu_exit_button = new Button(menu_group, LAYOUT("MENU_ITEM_6"), "Exit", STYLE_RED_42);

    settings_back_button = new Button(settings_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);
    settings_wall_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_3"), "Walls", STYLE_RED_42, false);
    settings_speed_slider = new Slider(settings_group, LAYOUT("MENU_ITEM_4"), 200U, 0U, STYLE_RED_42);
    settings_speed_label = new DataLabel<int>(settings_group, LAYOUT("MENU_ITEM_5"), "Speed", 0, STYLE_RED_STATIC_42);

    settings_speed_slider->add_range(CONST::SPEED_MIN, CONST::SPEED_MAX, "SPEED");
    settings_speed_slider->add_range(CONST::DELAY_MAX, CONST::DELAY_MIN, "DELAY");

    highscores_back_button = new Button(highscores_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);

    paused_paused_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_MAIN"), "Paused", STYLE_DARK_42);
    paused_info_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_SUB"), "Press 'p' to continue", STYLE_DARK_32);
    paused_resume_button = new Button(paused_group, LAYOUT("MENU_ITEM_1"), "Resume", STYLE_RED_42);
    paused_menu_button = new Button(paused_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_MAIN"), "Game over", STYLE_RED_42);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_SUB"), "Press 'r' to restart", STYLE_DARK_32);
    gameover_restart_button = new Button(gameover_group, LAYOUT("MENU_ITEM_8"), "Restart", STYLE_RED_42);
    gameover_menu_button = new Button(gameover_group, LAYOUT("MENU_ITEM_9"), "Main menu", STYLE_LIGHT_42);

    keybinds_up_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_1"), "Up", 350U, KEYBINDS("Up"), STYLE_RED_42);
    keybinds_down_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_2"), "Down", 350U, KEYBINDS("Down"), STYLE_RED_42);
    keybinds_left_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_3"), "Left", 350U, KEYBINDS("Left"), STYLE_RED_42);
    keybinds_right_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_4"), "Right", 350U, KEYBINDS("Right"), STYLE_RED_42);
    keybinds_pause_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_5"), "Pause", 350U, KEYBINDS("Pause"), STYLE_RED_42);
    keybinds_reset_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_6"), "Reset", 350U, KEYBINDS("Reset"), STYLE_RED_42);
    keybinds_exit_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_7"), "Exit", 350U, KEYBINDS("Exit"), STYLE_RED_42);
    
    keybinds_back_button = new Button(keybinds_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);
}


void Game::load_settings(void) {
    SETTINGS.load();
    
    settings_wall_switch->set_value((bool)(SETTINGS("WALLS")));
    settings_speed_slider->set_value(SETTINGS("SNAKE_STARTING_SPEED"), "SPEED");

    snake.set_delay(settings_speed_slider->get("DELAY"));
}


void Game::save_settings(void) {
    int speed_value = settings_speed_slider->get("SPEED");

    SETTINGS("SNAKE_STARTING_SPEED", speed_value);
    SETTINGS("WALLS", settings_wall_switch->get_value() ? CONST::UINT_ONE : CONST::UINT_ZERO);

    SETTINGS.save();
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

    int delay = settings_speed_slider->get("DELAY");
    snake = Snake(&grid, Vector(5U, 1U), delay, SETTINGS("SNAKE_STARTING_LENGTH"));

    apple.repos(&grid);
}


void Game::events(void) {
    keyboard.update();
    mouse.update();

    gui->events(mouse, keyboard);

    int speed_value = settings_speed_slider->get("SPEED");
    settings_speed_label->set_value(speed_value);

    if (window_header->is_close_clicked()) { stop(); }
    if (window_header->is_minimize_clicked()) { MinimizeWindow(); }

    check_for_transition();
    current_state->events(); // Ha ezt kikommentelem, akkor nem aktiválódik a slider
}


void Game::update(void) {
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