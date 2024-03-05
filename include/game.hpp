#pragma once

#include "grid.hpp"
#include "snake.hpp"
#include "apple.hpp"
#include "timer.hpp"
#include "event_handler.hpp"
#include "mouse_handler.hpp"
#include "window_header.hpp"
#include "state_machine.hpp"
#include "gui.hpp"
#include "widget_style.hpp"
#include "text_label.hpp"
#include "button.hpp"
#include "switch.hpp"
#include "slider.hpp"
#include "keybind_label.hpp"
#include "data_label.hpp"
#include "tools.hpp"
#include "score.hpp"


class Game: public StateMachine {

public:
    Game();

    ConfigData<int> SETTINGS = ConfigData<int>(PATH::SETTINGS);
    ConfigData<unsigned int> KEYBINDS = ConfigData<unsigned int>(PATH::KEYBINDS);

    KeyboardHandler keyboard = KeyboardHandler(&KEYBINDS);
    MouseHandler mouse;

    Grid grid;
    Snake snake;
    Apple apple;
    Score score;

    Gui* gui;

    WindowHeader* window_header = nullptr;

    WidgetGroup* menu_group;
    WidgetGroup* paused_group;
    WidgetGroup* gameover_group;
    WidgetGroup* settings_group;
    WidgetGroup* keybinds_group;
    WidgetGroup* highscores_group;
    WidgetGroup* gamedata_group;
    
    Button* menu_start_button = nullptr;
    Button* menu_settings_button = nullptr;
    Button* menu_keybinds_button = nullptr;
    Button* menu_highscores_button = nullptr;
    Button* menu_exit_button = nullptr;

    Button* settings_back_button = nullptr;
    Switch* settings_wall_switch = nullptr;
    Slider* settings_speed_slider = nullptr;
    DataLabel<int>* settings_speed_label = nullptr;

    Button* keybinds_back_button = nullptr;
    KeybindLabel* keybinds_up_label = nullptr;
    KeybindLabel* keybinds_down_label = nullptr;
    KeybindLabel* keybinds_left_label = nullptr;
    KeybindLabel* keybinds_right_label = nullptr;
    KeybindLabel* keybinds_pause_label = nullptr;
    KeybindLabel* keybinds_reset_label = nullptr;
    KeybindLabel* keybinds_exit_label = nullptr;

    Button* highscores_back_button = nullptr;
    
    TextLabel* paused_paused_label = nullptr;
    TextLabel* paused_info_label = nullptr;
    Button* paused_resume_button = nullptr;
    Button* paused_menu_button = nullptr;

    TextLabel* gameover_gameover_label = nullptr;
    TextLabel* gameover_info_label = nullptr;
    Button* gameover_restart_button = nullptr;
    Button* gameover_menu_button = nullptr;

    TextLabel* gamedata_statistics_label = nullptr;
    TextLabel* gamedata_gametitle_label = nullptr;
    DataLabel<unsigned int>* gamedata_score_label = nullptr;
    DataLabel<unsigned int>* gamedata_apples_label = nullptr;
    DataLabel<unsigned int>* gamedata_bonuses_label = nullptr;

    void init_window(void);
    void init_objects(void);
    void init_states(void);
    void init_gui(void);

    void load_settings(void);
    void save_settings(void);

    void start(void);
    void stop(void);
    void reset(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;

};