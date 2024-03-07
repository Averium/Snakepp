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

    - different style structs for different widgets

    - separate keymap for character keys and mod keys

    - highscores system
    - highscores file

    - sound system
    - ploishing
*/