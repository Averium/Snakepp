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
    - change or automate widget layer situation

TODO:
    - UPGRADE MAKEFILE FOR AUTOMATIC DEPENDENCIES

    - add unconfigured keypress mode to KeyboardHandler that tracks all keys, but only when the mode is active
        - (text input and key config scenarios)

    - keybind widget (datalabel subclass) or just use datalabel class and solve with that
    - keybind window

    - text input widget (datalabel subclass)

    - highscores system
    - highscores file
    - highscores window

    - sound system
    - ploishing
*/