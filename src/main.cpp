#include "main.h"


int main(void) {
    InitWindow(GRID_COLUMNS * CELL_SIZE, GRID_ROWS * CELL_SIZE, TITLE);
    SetTargetFPS(FPS);

    Game game = Game();
    game.start();

    CloseWindow();
}