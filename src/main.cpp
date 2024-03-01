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
    - datalabel class
    - slider class

    - always active widget groups & window header as a widget

    file handling
        - settings file
        - keybinding file
        - highscores file

    sound system
*/