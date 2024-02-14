#pragma once

#include "grid.h"
#include "snake.h"
#include "apple.h"
#include "timer.h"
#include "event_handler.h"
#include "mouse_handler.h"
#include "window_header.h"
#include "state_machine.h"


class Game {

public:
    Game();
    WindowHeader header;

    Timer logic_timer;
    EventHandler key_handler;
    MouseHandler mouse_handler;

    Grid grid;
    Snake snake;
    Apple apple;

    void init_objects(void);
    void init_states(void);
    void init_events(void);

    void start(void);
    void reset(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;
    bool paused;
    bool game_over;

};