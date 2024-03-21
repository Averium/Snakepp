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
    SetRandomSeed(555);
}


void Game::init_objects(void) {
    grid = Grid(LAYOUT("GRID"));

    int delay = settings_speed_slider->get("DELAY");
    snake = Snake(grid, Vector(5U, 1U), delay, SETTINGS("SNAKE_STARTING_LENGTH"));

    apple.repos(grid);
    score.reset();
}


void Game::init_states(void) {
    init(new StartupState(this));
    add_state(new MenuState(this));
    add_state(new SettingsState(this));
    add_state(new KeyBindsState(this));
    add_state(new HighScoresState(this));
    add_state(new AboutState(this));
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
    begin_group = new WidgetGroup(gui);
    about_group = new WidgetGroup(gui);

    window_header = new WindowHeader(gui, LAYOUT("HEADER"), "Hold to move the window", STYLE_HEADER);
    gui->activate_item(window_header);

    menu_start_button = new Button(menu_group, LAYOUT("MENU_ITEM_1"), "Play", STYLE_RED_3);
    menu_settings_button = new Button(menu_group, LAYOUT("MENU_ITEM_3"), "Settings", STYLE_LIGHT_2);
    menu_keybinds_button = new Button(menu_group, LAYOUT("MENU_ITEM_4"), "Keybinds", STYLE_LIGHT_2);
    menu_highscores_button = new Button(menu_group, LAYOUT("MENU_ITEM_5"), "High scores", STYLE_LIGHT_2);
    menu_about_button = new Button(menu_group, LAYOUT("MENU_ITEM_7"), "About", STYLE_LIGHT_2);
    menu_exit_button = new Button(menu_group, LAYOUT("MENU_ITEM_9"), "Exit", STYLE_LIGHT_2);

    settings_speed_label = new DataLabel<int>(settings_group, LAYOUT("MENU_ITEM_1"), "Speed: ", 0, STYLE_LIGHT_2_SF);
    settings_speed_slider = new Slider(settings_group, LAYOUT("MENU_ITEM_2"), 200U, 0U, STYLE_SETTINGS_SLIDER);
    settings_wall_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_4"), "Walls", STYLE_LIGHT_2, false);
    settings_theme_switch = new Switch(settings_group, LAYOUT("MENU_ITEM_7"), "Theme", STYLE_LIGHT_2, false, "Dark", "Light");
    settings_back_button = new Button(settings_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_2);

    settings_speed_slider->add_range(SPEED_MIN, SPEED_MAX, "SPEED");
    settings_speed_slider->add_range(DELAY_MAX, DELAY_MIN, "DELAY");

    paused_paused_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_MAIN"), "Paused", STYLE_DARK_2);
    paused_info_label = new TextLabel(paused_group, LAYOUT("INFO_LABEL_SUB"), "Press 'p' to continue", STYLE_DARK_1);
    paused_resume_button = new Button(paused_group, LAYOUT("MENU_ITEM_1"), "Resume", STYLE_RED_2);
    paused_menu_button = new Button(paused_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_2);

    gameover_gameover_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_MAIN"), "Game over", STYLE_RED_2);
    gameover_info_label = new TextLabel(gameover_group, LAYOUT("INFO_LABEL_SUB"), "Press 'r' to restart", STYLE_DARK_1);
    gameover_restart_button = new Button(gameover_group, LAYOUT("MENU_ITEM_1"), "Restart", STYLE_RED_2);
    gameover_menu_button = new Button(gameover_group, LAYOUT("MENU_ITEM_2"), "Main menu", STYLE_LIGHT_2);

    newhighscore_newhighscore_label = new TextLabel(newhighscore_group, LAYOUT("MENU_ITEM_1"), "New highscore!", STYLE_DARK_3);
    newhighscore_name_label = new TextInput(newhighscore_group, LAYOUT("MENU_ITEM_3"), "Enter your name", STYLE_HIGHSCORE_INPUT);
    newhighscore_done_button = new Button(newhighscore_group, LAYOUT("MENU_ITEM_6"), "Done", STYLE_LIGHT_2);

    keybinds_up_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_1"), "Up", keyboard.decode_key(KEYBINDS("Up")), STYLE_KEYBIND_LABEL);
    keybinds_down_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_2"), "Down", keyboard.decode_key(KEYBINDS("Down")), STYLE_KEYBIND_LABEL);
    keybinds_left_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_3"), "Left", keyboard.decode_key(KEYBINDS("Left")), STYLE_KEYBIND_LABEL);
    keybinds_right_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_4"), "Right", keyboard.decode_key(KEYBINDS("Right")), STYLE_KEYBIND_LABEL);
    keybinds_pause_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_5"), "Pause", keyboard.decode_key(KEYBINDS("Pause")), STYLE_KEYBIND_LABEL);
    keybinds_reset_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_6"), "Reset", keyboard.decode_key(KEYBINDS("Reset")), STYLE_KEYBIND_LABEL);
    keybinds_exit_label = new KeybindLabel(keybinds_group, LAYOUT("MENU_ITEM_7"), "Exit", keyboard.decode_key(KEYBINDS("Exit")), STYLE_KEYBIND_LABEL);
    keybinds_back_button = new Button(keybinds_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_2);

    begin_info_label = new TextLabel(begin_group, LAYOUT("GRID_CENTER"), "Press any key to start", STYLE_DARK_2);
    
    gamedata_gametitle_label = new TextLabel(gamedata_group, LAYOUT("DATA_TITLE_LABEL"), "Snake", STYLE_DARK_3, MIDTOP);
    gamedata_statistics_label = new TextLabel(gamedata_group, LAYOUT("DATA_STATISTICS_LABEL"), "Statistics", STYLE_DARK_2);
    gamedata_statistics_label = new TextLabel(gamedata_group, LAYOUT("DATA_SETTINGS_LABEL"), "Settings", STYLE_DARK_2);
    gamedata_apples_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_APPLES_LABEL"), "Apples: ", 0, STYLE_RED_2_SF, MIDLEFT);
    gamedata_bonuses_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_BONUSES_LABEL"), "Bonuses: ", 0, STYLE_BLUE_2_SF, MIDLEFT);
    gamedata_score_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_SCORE_LABEL"), "Score: ", 0, STYLE_LIGHT_2_SF, MIDLEFT);
    gamedata_speed_label = new DataLabel<unsigned int>(gamedata_group, LAYOUT("DATA_SPEED_LABEL"), "Speed: ", 0, STYLE_LIGHT_2_SF, MIDLEFT);
    gamedata_walls_label = new DataLabel<std::string>(gamedata_group, LAYOUT("DATA_WALLS_LABEL"), "Walls: ", "", STYLE_LIGHT_2_SF, MIDLEFT);
    
    highscores_info_label = new TextLabel(highscores_group, LAYOUT("MENU_ITEM_1"), "Highscores", STYLE_DARK_3);
    highscores_back_button = new Button(highscores_group, LAYOUT("MENU_ITEM_9"), "Back", STYLE_LIGHT_2);

    about_title_label = new TextLabel(about_group, LAYOUT("TITLE"), "About", STYLE_DARK_3);
    about_info_label = new TextLabelMultiline(about_group, LAYOUT("MENU_ITEM_1"), ABOUT, WIDGET_LINE_SPACING, STYLE_DARK_1, MIDTOP);

    Vector link_pos = about_info_label->bottomleft() + Vector(UINT_ZERO, WIDGET_LINE_SPACING);
    about_link_button = new Button(about_group, link_pos, GITHUB_LINK, STYLE_LINK_BUTTON, TOPLEFT);
    about_back_button = new Button(about_group, LAYOUT("MENU_ITEM_10"), "Back", STYLE_LIGHT_2);

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
    settings_theme_switch->set_value((bool)(SETTINGS("THEME")));
    settings_speed_slider->set_value(SETTINGS("SNAKE_STARTING_SPEED"), "SPEED");

    snake.set_delay(settings_speed_slider->get("DELAY"));
}


void Game::save_settings(void) {
    int speed_value = settings_speed_slider->get("SPEED");

    SETTINGS("SNAKE_STARTING_SPEED", speed_value);
    SETTINGS("WALLS", settings_wall_switch->get_value() ? UINT_ONE : UINT_ZERO);
    SETTINGS("THEME", settings_theme_switch->get_value() ? UINT_ONE : UINT_ZERO);

    SETTINGS.save();
}


void Game::update_highscores(void) {
    unsigned int index = UINT_ZERO;
    for (const auto& pair : score.sorted_pairs()) {
        highscore_labels[index]->set_value(pair.second);
        highscore_labels[index++]->set_text(pair.first);
    }
}


void Game::open_link(std::string link) const {
    std::string command = "start " + link;
    std::system(command.c_str());
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
    snake = Snake(grid, Vector(5U, 1U), delay, SETTINGS("SNAKE_STARTING_LENGTH"));

    apple.repos(grid);
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

    if (about_link_button->is_clicked()) { open_link(GITHUB_LINK); }

    check_for_transition();
    current_state->events();
}


void Game::update(void) {
    current_state->update();
}


void Game::render(void) {
    
    BeginDrawing();

    unsigned int theme_index = (unsigned int)(settings_theme_switch->get_value());

    ClearBackground(THEME[theme_index]("GREY2"));
    grid.render_background(THEME[theme_index]);
    current_state->render(THEME[theme_index]);
    gui->render(THEME[theme_index]);

    EndDrawing();
}


void Game::loop(void) {
    while (running == true) {
        events();
        update();
        render();
    }
}