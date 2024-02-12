#pragma once

#include "grid.h"
#include "snake.h"
#include "apple.h"
#include "timer.h"
#include "keyboard_handler.h"


class Game {

public:
    Game();

    Timer logic_timer;
    KeyboardHandler event_handler;

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