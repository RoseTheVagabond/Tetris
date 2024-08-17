#include <raylib.h>
#include "game.h"

auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    auto colors = getCellColours();

    Game game = Game();

    while(!WindowShouldClose()) {
        game.handleInput();
        BeginDrawing();
        ClearBackground(colors[4]);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}