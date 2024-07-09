#include <raylib.h>
#include "grid.h"

auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(grid.colors[4]);

        grid.draw();



        EndDrawing();
    }
    CloseWindow();
}