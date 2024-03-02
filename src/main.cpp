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
    - data label class
    - slider class

    - always active widget groups & window header as a widget

    - settings file
        - speed
        - walls

    - keybinding file
    - highscores file

    - sound system
    - ploishing
*/