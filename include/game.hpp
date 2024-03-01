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
#include "data_file.hpp"
#include "layout_data.hpp"


class Game: public StateMachine {

public:
    Game();
    
    WindowHeader header;

    Timer logic_timer;
    EventHandler key_handler;
    MouseHandler mouse_handler;

    Grid grid;
    Snake snake;
    Apple apple;

    Gui* gui = nullptr;

    WidgetGroup* menu_group = nullptr;
    WidgetGroup* paused_group = nullptr;
    WidgetGroup* gameover_group = nullptr;
    WidgetGroup* settings_group = nullptr;
    WidgetGroup* keybinds_group = nullptr;
    WidgetGroup* highscores_group = nullptr;
    
    Button* menu_start_button = nullptr;
    Button* menu_settings_button = nullptr;
    Button* menu_keybinds_button = nullptr;
    Button* menu_highscores_button = nullptr;
    Button* menu_exit_button = nullptr;

    Button* settings_back_button = nullptr;
    Switch* settings_test_switch = nullptr;

    Button* keybinds_back_button = nullptr;
    Button* highscores_back_button = nullptr;
    
    TextLabel* paused_paused_label = nullptr;
    TextLabel* paused_info_label = nullptr;

    TextLabel* gameover_gameover_label = nullptr;
    TextLabel* gameover_info_label = nullptr;

    void init_window(void);
    void init_objects(void);
    void init_states(void);
    void init_events(void);
    void init_gui(void);

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