#include "main.h"


int main(void) {
    InitWindow(LAYOUT::WINDOW.x, LAYOUT::WINDOW.y, TITLE);
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(FPS);

    Game game = Game();
    game.start();

    CloseWindow();
}


/*
TODO:
    make room for game widgets
    implement game widgets
    implement state machine
    implement interface
        - menu screen
        - game over screen
        - start screen
        - game screen
        - settings screen
        - key bindings screen
        - highscore screen
    implement file handline
*/