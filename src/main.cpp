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
FIXME:
    - settings slider jumps to cursor upon entering the state

TODO:
    - UPGRADE MAKEFILE FOR AUTOMATIC DEPENDENCIES

    - create a value map class that can map any value to other preset ranges easily

    - keybind widget (also datalabel subclass)
    - finish gui

    - settings file
        - speed
        - walls

    - keybinding file
    - highscores file

    - sound system
    - ploishing
*/