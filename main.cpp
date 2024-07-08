#include <raylib.h>

auto main() -> int {
    Color darkBlue = {0, 29, 61, 255};

    InitWindow(300, 600, "Tetris");

    SetTargetFPS(60);
    while(WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkBlue);
        EndDrawing();
    }
    CloseWindow();
}