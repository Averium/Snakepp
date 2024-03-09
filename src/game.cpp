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
    score.reset();
}


void Game::init_states(void) {
    init(new StartupState(this));
    add_state(new MenuState(this));
    add_state(new SettingsState(this));
    add_state(new KeyBindsState(this));
    add_state(new HighScoresState(this));
    add_state(new PausedState(this));
    add_state(new BeginState(this));
    add_state(new RunningState(this));
    add_state(new GameOverState(this));
    add_state(new NewHighscoreState(this));
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
    newhighscore_group = new WidgetGroup(gui);
    gamedata_group = new WidgetGroup(gui);

    window_header = new WindowHeader(gui, LAYOUT("HEADER"), "Hold to move the window", STYLE_HEADER);
    gui->activate_item(window_header);

    menu_start_button = new Button(menu_group, LAYOUT("MENU_ITEM_1"), "Play", STYLE_RED_72);
    menu_settings_button = new Button(menu_group, LAYOUT("MENU_ITEM_3"), "Settings", STYLE_LIGHT_42);
    menu_keybinds_button = new Button(menu_group, LAYOUT("MENU_ITEM_4"), "Keybinds", STYLE_LIGHT_42);
    menu_highscores_button = new Button(menu_group, LAYOUT("MENU_ITEM_5"), "High scores", STYLE_LIGHT_42);
    menu_exit_button = new Button(menu_group, LAYOUT("MENU_ITEM_9"), "Exit", STYLE_RED_42);

    settings_back_button = new Button(settings_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);
    settings_wall_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_5"), "Walls", STYLE_RED_42, false);
    settings_speed_slider = new Slider(settings_group, LAYOUT("MENU_ITEM_3"), 200U, 0U, STYLE_RED_42);
    settings_speed_label = new DataLabel<int>(settings_group, LAYOUT("MENU_ITEM_2"), "Speed: ", 0, STYLE_RED_STATIC_42);

    settings_speed_slider->add_range(SPEED_MIN, SPEED_MAX, "SPEED");
    settings_speed_slider->add_range(DELAY_MAX, DELAY_MIN, "DELAY");

    paused_paused_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_MAIN"), "Paused", STYLE_DARK_42);
    paused_info_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_SUB"), "Press 'p' to continue", STYLE_DARK_32);
    paused_resume_button = new Button(paused_group, LAYOUT("MENU_ITEM_1"), "Resume", STYLE_RED_42);
    paused_menu_button = new Button(paused_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_MAIN"), "Game over", STYLE_RED_42);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_SUB"), "Press 'r' to restart", STYLE_DARK_32);
    gameover_restart_button = new Button(gameover_group, LAYOUT("MENU_ITEM_1"), "Restart", STYLE_RED_42);
    gameover_menu_button = new Button(gameover_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_42);

    newhighscore_newhighscore_label = new TextLabel(newhighscore_group, LAYOUT("MENU_ITEM_1"), "New highscore!", STYLE_DARK_72);
    newhighscore_name_label = new TextInput(newhighscore_group, LAYOUT("MENU_ITEM_3"), "Enter your name", STYLE_HIGHSCORE_INPUT);
    newhighscore_done_button = new Button(newhighscore_group, LAYOUT("MENU_ITEM_6"), "Done", STYLE_LIGHT_42);

    keybinds_up_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_1"), "Up", keyboard.decode_key(KEYBINDS("Up")), STYLE_KEYBIND_LABEL);
    keybinds_down_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_2"), "Down", keyboard.decode_key(KEYBINDS("Down")), STYLE_KEYBIND_LABEL);
    keybinds_left_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_3"), "Left", keyboard.decode_key(KEYBINDS("Left")), STYLE_KEYBIND_LABEL);
    keybinds_right_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_4"), "Right", keyboard.decode_key(KEYBINDS("Right")), STYLE_KEYBIND_LABEL);
    keybinds_pause_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_5"), "Pause", keyboard.decode_key(KEYBINDS("Pause")), STYLE_KEYBIND_LABEL);
    keybinds_reset_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_6"), "Reset", keyboard.decode_key(KEYBINDS("Reset")), STYLE_KEYBIND_LABEL);
    keybinds_exit_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_7"), "Exit", keyboard.decode_key(KEYBINDS("Exit")), STYLE_KEYBIND_LABEL);
    
    keybinds_back_button = new Button(keybinds_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);

    gamedata_gametitle_label = new TextLabel(gamedata_group, LAYOUT("DATA_TITLE_LABEL"), "Snake", STYLE_DARK_72, MIDTOP);
    gamedata_statistics_label = new TextLabel(gamedata_group, LAYOUT("DATA_STATISTICS_LABEL"), "Statistics", STYLE_DARK_42);
    gamedata_statistics_label = new TextLabel(gamedata_group, LAYOUT("DATA_SETTINGS_LABEL"), "Settings", STYLE_DARK_42);
    gamedata_apples_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_APPLES_LABEL"), "Apples: ", 0, STYLE_STAT_LABEL, MIDLEFT);
    gamedata_bonuses_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_BONUSES_LABEL"), "Bonuses: ", 0, STYLE_STAT_LABEL, MIDLEFT);
    gamedata_score_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_SCORE_LABEL"), "Score: ", 0, STYLE_SCORE_LABEL, MIDLEFT);
    gamedata_speed_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_SPEED_LABEL"), "Speed: ", 0, STYLE_SCORE_LABEL, MIDLEFT);
    gamedata_walls_label = new DataLabel<std::string>(gamedata_group, LAYOUT("DATA_WALLS_LABEL"), "Walls: ", "", STYLE_SCORE_LABEL, MIDLEFT);
    
    highscores_info_label = new TextLabel(highscores_group, LAYOUT("MENU_ITEM_1"), "Highscores", STYLE_DARK_72);
    highscores_back_button = new Button(highscores_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_42);

    unsigned int index = UINT_ZERO;
    for (const auto& pair : score.sorted_pairs()) {
        Vector position = LAYOUT("MENU_ITEM_" + std::to_string(index + 3U));
        highscore_labels[index] = new DataLabel<unsigned int>(highscores_group, position, pair.first, pair.second, STYLE_HIGHSCORE_LABEL);
        ++index;
    }

    gui->activate_item(gamedata_group);
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
    SETTINGS("WALLS", settings_wall_switch->get_value() ? UINT_ONE : UINT_ZERO);

    SETTINGS.save();
}


void Game::update_highscores(void) {
    unsigned int index = UINT_ZERO;
    for (const auto& pair : score.sorted_pairs()) {
        highscore_labels[index]->set_value(pair.second);
        highscore_labels[index++]->set_text(pair.first);
    }
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
    score.reset();
}


void Game::events(void) {
    keyboard.update();
    mouse.update();

    gui->events(mouse, keyboard);

    int speed_value = settings_speed_slider->get("SPEED");
    settings_speed_label->set_value(speed_value);

    gamedata_score_label->set_value(score.get_score());
    gamedata_apples_label->set_value(score.get_apples());
    gamedata_bonuses_label->set_value(score.get_bonuses());

    gamedata_speed_label->set_value(speed_value);
    gamedata_walls_label->set_value(settings_wall_switch->value_text());

    if (window_header->is_close_clicked()) { stop(); }
    if (window_header->is_minimize_clicked()) { MinimizeWindow(); }

    check_for_transition();
    current_state->events();
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