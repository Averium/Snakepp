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

    int delay = map_value<int>(SETTINGS("SNAKE_STARTING_SPEED"), CONST::SPEED_MIN, CONST::SPEED_MAX, CONST::DELAY_MAX, CONST::DELAY_MIN);
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
    settings_wall_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_2"), "Walls", STYLE_RED_42, false, CENTER, 2);
    settings_speed_slider = new Slider(settings_group, LAYOUT("MENU_ITEM_3"), 200U, 0U, STYLE_RED_42, CENTER, 3);
    settings_speed_label = new DataLabel<int>(settings_group, LAYOUT("MENU_ITEM_4"), "Speed", 2, STYLE_RED_STATIC_42, CENTER, 4);

    settings_speed_slider->add_range(CONST::SPEED_MIN, CONST::SPEED_MAX, "SPEED");
    settings_speed_slider->add_range(CONST::DELAY_MAX, CONST::DELAY_MIN, "DELAY");

    highscores_back_button = new Button(highscores_group, LAYOUT("MENU_ITEM_6"), "Back", STYLE_LIGHT_42, CENTER);

    paused_paused_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_MAIN"), "Paused", STYLE_DARK_42, CENTER, 1);
    paused_info_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_SUB"), "Press 'p' to continue", STYLE_DARK_32, CENTER, 2);
    paused_resume_button = new Button(paused_group, LAYOUT("MENU_ITEM_1"), "Resume", STYLE_RED_42, CENTER, 3);
    paused_menu_button = new Button(paused_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42, CENTER, 4);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_MAIN"), "Game over", STYLE_RED_42, CENTER, 1);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_SUB"), "Press 'r' to restart", STYLE_DARK_32, CENTER, 2);
    gameover_restart_button = new Button(gameover_group, LAYOUT("MENU_ITEM_1"), "Restart", STYLE_RED_42, CENTER, 3);
    gameover_menu_button = new Button(gameover_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42, CENTER, 4);

    keybinds_up_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_1"), "Up", 350U, KEYBINDS("Up"), STYLE_RED_42, CENTER, 1);
    keybinds_down_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_2"), "Down", 350U, KEYBINDS("Down"), STYLE_RED_42, CENTER, 2);
    keybinds_left_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_3"), "Left", 350U, KEYBINDS("Left"), STYLE_RED_42, CENTER, 3);
    keybinds_right_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_4"), "Right", 350U, KEYBINDS("Right"), STYLE_RED_42, CENTER, 4);
    keybinds_pause_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_5"), "Pause", 350U, KEYBINDS("Pause"), STYLE_RED_42, CENTER, 5);
    keybinds_reset_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_6"), "Reset", 350U, KEYBINDS("Reset"), STYLE_RED_42, CENTER, 6);
    keybinds_exit_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_7"), "Exit", 350U, KEYBINDS("Exit"), STYLE_RED_42, CENTER, 7);
    
    keybinds_back_button = new Button(keybinds_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42, CENTER, 8);
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
    SETTINGS("WALLS", settings_wall_switch->get_value() ? 1U : 0U);

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

    int delay = map_value<int>(SETTINGS("SNAKE_STARTING_SPEED"), CONST::SPEED_MIN, CONST::SPEED_MAX, CONST::DELAY_MAX, CONST::DELAY_MIN);
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