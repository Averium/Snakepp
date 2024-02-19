#include "main.h"


int main(void) {
    InitWindow(LAYOUT::WINDOW.x, LAYOUT::WINDOW.y, "");
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(CONST::FPS);

    Game game = Game();
    game.start();

    CloseWindow();
}


/*
TODO:
    interface system
        - interface class
        - register class template
        - widgetgroup class
        - widgetstyle class
        - widget class
        - textlabel class
        - datalabel class
        - button class
        - switch class
        - slider class

    file handling
        - settings file
        - keybinding file
        - highscores file

    sound system
*/