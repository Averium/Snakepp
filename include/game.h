#pragma once

#include "grid.h"
#include "snake.h"
#include "apple.h"
#include "timer.h"
#include "event_handler.h"
#include "mouse_handler.h"
#include "window_header.h"
#include "state_machine.h"
#include "gui.h"
#include "widget_style.h"
#include "text_label.h"
#include "button.h"


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
    Button* keybinds_back_button = nullptr;
    Button* highscores_back_button = nullptr;
    
    TextLabel* paused_paused_label = nullptr;
    TextLabel* paused_info_label = nullptr;

    TextLabel* gameover_gameover_label = nullptr;
    TextLabel* gameover_info_label = nullptr;

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