#include <raylib.h>
#include "game.h"

//auto lastUpdateTime = 0;
//
//auto eventTriggered(double interval) -> bool {
//    double currentTime = GetTime();
//    if(currentTime - lastUpdateTime >= interval) {
//        lastUpdateTime = currentTime;
//        return true;
//    }
//    return false;
//}

auto lastUpdateTime = 0.0;
auto deltaTime = 0.0;

auto eventTriggered(double interval) -> bool {
    double currentTime = GetTime();
    deltaTime += currentTime - lastUpdateTime;
    lastUpdateTime = currentTime;

    if (deltaTime >= interval) {
        deltaTime = 0.0;
        return true;
    }
    return false;
}


auto main() -> int {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    auto colors = getCellColours();

    Game game = Game();

    while(!WindowShouldClose()) {
        game.handleInput();
        if(eventTriggered(0.4)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(colors[4]);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}