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

    Gui* gui;

    WidgetGroup* menu_group;
    WidgetGroup* paused_group;
    WidgetGroup* gameover_group;
    
    Button* menu_start_button;
    Button* menu_settings_button;
    Button* menu_keybinds_button;
    Button* menu_highscores_button;
    Button* menu_exit_button;
    
    TextLabel* paused_paused_label;

    TextLabel* gameover_gameover_label;
    TextLabel* gameover_info_label;

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