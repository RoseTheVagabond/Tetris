#include <raylib.h>
#include "game.h"
#include <iostream>

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

    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);
    auto colors = getCellColours();

    Font font = LoadFontEx("videophreak.ttf", 64, 0, 0);

    Game game = Game();

    while(!WindowShouldClose()) {
        UpdateMusicStream(game.music);
        game.handleInput();
        if(eventTriggered(0.4)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(colors[4]);

        DrawTextEx(font, "Score", {355, 55}, 38, 2, WHITE);
        DrawRectangleRounded({320, 95, 170, 60}, 0.3, 6, colors[1]);
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 105}, 38, 2, WHITE);

        DrawTextEx(font, "Next", {370, 215}, 38, 2, WHITE);
        DrawRectangleRounded({320, 255, 170, 180}, 0.3, 6, colors[1]);

        if(game.gameOver) {
            DrawTextEx(font, "GAME OVER", {320, 490}, 28, 2, WHITE);
        }

        game.draw();
        EndDrawing();
    }
    CloseWindow();
}