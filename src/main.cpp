#include "main.hpp"
#include "debug.hpp"

#define TEST 0


int main(void) {
    if (TEST) {

    }

    else {
        Game game = Game();
        game.start();

        CloseWindow();
    }
}


/*
TODO:
    - UPGRADE MAKEFILE FOR AUTOMATIC DEPENDENCIES

    - text input widget (datalabel subclass)

    - highscores system
    - highscores file
    - highscores window

    - sound system
    - ploishing
*/