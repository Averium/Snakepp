#pragma once

#include "grid.h"
#include "snake.h"
#include "apple.h"
#include "timer.h"
#include "event_handler.h"
#include "mouse_handler.h"
#include "window_header.h"


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