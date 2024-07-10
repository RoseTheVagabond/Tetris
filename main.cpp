#include <raylib.h>
#include "grid.h"
#include "colours.h"
#include "tetrominos.cpp"

auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    auto colors = getCellColours();

    Grid grid = Grid();

    LMino l = LMino();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(colors[4]);

        grid.draw();
        l.draw();

        EndDrawing();
    }
    CloseWindow();
}