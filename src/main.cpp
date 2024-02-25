#include "main.h"
#include "debug.h"


#define TEST 0


int main(void) {
    if (TEST) {
        Rect rect = Rect(10, 20, 100, 100);
        rect.bottomleft(Vector(500, 400));
        rect.print();
    }
    else {
        InitWindow(LAYOUT::WINDOW.x, LAYOUT::WINDOW.y, "");
        SetWindowState(FLAG_WINDOW_UNDECORATED);
        SetTargetFPS(CONST::FPS);

        Game game = Game();
        game.start();

        CloseWindow();
    }
}


/*
TODO:
    - datalabel class
    - switch class
    - slider class

    file handling
        - settings file
        - keybinding file
        - highscores file

    sound system
*/