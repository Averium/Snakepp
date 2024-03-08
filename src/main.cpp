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
    - add flashing cursor line to text input widget

    - show highscores on highscores screen
    - show highscores screen after registering a new highscore
    - remove "restart" and "menu" buttons from new_highscore screen and add "ok" button

    - sound system
    - ploishing
*/