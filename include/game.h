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
#include "text_label.h"

#include "running_state.h"
#include "paused_state.h"
#include "gameover_state.h"


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

    WidgetGroup* paused_group;
    WidgetGroup* gameover_group;
    
    TextLabel* paused_label;
    TextLabel* gameover_label;

    void init_objects(void);
    void init_states(void);
    void init_events(void);
    void init_gui(void);

    void start(void);
    void reset(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;

};