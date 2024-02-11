#pragma once

#include "grid.h"


class Game {

public:
    Game();

    Grid grid;

    void start(void);

    void events(void);
    void update(void);
    void render(void);
    void loop(void);

private:
    bool running;
    bool paused;

};