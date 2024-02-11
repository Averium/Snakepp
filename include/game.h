#pragma once

#include "grid.h"
#include "snake.h"
#include "timer.h"
#include "event_handler.h"


class Game {

public:
    Game();

    Timer logic_timer;
    EventHandler event_handler;

    Grid grid;
    Snake snake;

    void start(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;
    bool paused;

};