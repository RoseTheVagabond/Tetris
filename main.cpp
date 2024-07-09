#include <raylib.h>
#include "grid.h"

auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.print();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(grid.colors[1]);

        grid.draw();



        EndDrawing();
    }
    CloseWindow();
}