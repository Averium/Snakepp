#pragma once

#include "grid.h"
#include "snake.h"
#include "timer.h"


class Game {

public:
    Game();

    Grid grid;
    Snake snake;
    Timer logic_timer;

    void start(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;
    bool paused;

};