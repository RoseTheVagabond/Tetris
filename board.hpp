#ifndef _BOARD_
#define _BOARD_

#include <SFML/Graphics.hpp>
#include <vector>
#include "pieces.hpp"
#include "IO.hpp" // Include IO.hpp to use sf::RenderWindow

struct Board {

    // Constant fields
    int const boardWidth = 10;
    int const boardHeight = 20;
    int const blockSize = 20;
    int const blocksInPiece = 5;
    enum { EMPTY = 0, FULL = 1, ROTATION = 2 };

    std::shared_ptr<Piece> pieces; // Use shared_ptr for Piece
    std::unique_ptr<sf::RenderWindow> window; // Keep a raw pointer for window
    int boardXPosition = 0;
    int boardYPosition = 0;
    std::vector<std::vector<int>> board;

    // Adjust the constructor to use shared_ptr and raw pointer
    Board(std::shared_ptr<Piece> pieces, sf::RenderWindow* window);

    auto initBoard() -> void;
    auto storePiece(int y, int x, int piece, int rotation) -> void;
    auto isGameOver() -> bool;
    auto removeRow(int rowNumber) -> void;
    auto isEmptyBlock(int y, int x) -> bool;
    auto isMovementPossible(int y, int x, int piece, int rotation) -> bool;
    auto getPiecePositionX(int piecePositionX) -> int;
    auto getPiecePositionY(int piecePositionY) -> int;
};

#endif // _BOARD_
