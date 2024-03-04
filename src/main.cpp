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

    - keybind widget (also datalabel subclass) or just use datalabel class
    - finish gui

    - keybinding file
    - highscores file

    - sound system
    - ploishing
*/