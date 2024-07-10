#include <raylib.h>
#include "grid.h"
#include "colours.h"

auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    auto colors = getCellColours();

    Grid grid = Grid();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(colors[4]);

        grid.draw();



        EndDrawing();
    }
    CloseWindow();
}