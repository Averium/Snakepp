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

    - change keybind widget from TextLabel subclass to DataLabel subclass with fixed width
    
    - text input widget (datalabel subclass)

    - highscores system
    - highscores file
    - highscores window

    - sound system
    - ploishing
*/