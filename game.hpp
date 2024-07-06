#ifndef _GAME_
#define _GAME_

#include "board.hpp"
#include "pieces.hpp"
#include "IO.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

struct Game {

    int const boardLineWidth = 10;
    int screenHeight = 0;
    Board* board;
    Piece* pieces;
    IO* io;

    // Current piece:
    int currentPieceType = 0;
    int currentPieceRotation = 0;
    int currentPieceX = 0;
    int currentPieceY = 0;

    // Next piece:
    int nextPieceType = 0;
    int nextPieceRotation = 0;
    int nextPieceX = 0;
    int nextPieceY = 0;

    Game(Board* board, Piece* pieces, IO* io, sf::RenderWindow* window);

    auto getRandomNumber(int min, int max) -> int;
    auto initGame() -> void;
    auto createNewPiece() -> void;
    auto drawPiece(int y, int x, int pieceType, int rotation) -> void;
    auto drawBoard() -> void;
    auto drawScene() -> void;
};

#endif // _GAME_
