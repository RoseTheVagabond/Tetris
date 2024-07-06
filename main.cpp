#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <memory> // Include memory header for smart pointers

auto main() -> int {
    std::shared_ptr<IO> io = std::make_shared<IO>(); // Use shared_ptr for IO
    int waitTime = 700;
    int screenHeight = io->getScreenHeight();
    std::shared_ptr<Piece> pieces = std::make_shared<Piece>(); // Use shared_ptr for Piece
    std::shared_ptr<Board> board = std::make_shared<Board>(pieces, io->window.get()); // Use get() to pass raw pointer to Board
    std::shared_ptr<Game> game = std::make_shared<Game>(board, pieces, io, io->window.get()); // Use get() to pass raw pointer to Game
    sf::Clock clock;
    long time = clock.getElapsedTime().asMilliseconds();

    while(io->window->isOpen()) {
        io->clearWindow();
        game->drawScene();
        io->updateScreen();

        int key = io->pollkey();

        switch(key) {
            case (sf::Keyboard::Right) :
            {
                if(board->isMovementPossible(game->currentPieceX + 1, game->currentPieceY, game->currentPieceType, game->currentPieceRotation)) {
                    game->currentPieceX++;
                }
                break;
            }
            case (sf::Keyboard::Left) :
            {
                if(board->isMovementPossible(game->currentPieceX - 1, game->currentPieceY, game->currentPieceType, game->currentPieceRotation)) {
                    game->currentPieceX--;
                }
                break;
            }
            case (sf::Keyboard::Down) :
            {
                if(board->isMovementPossible(game->currentPieceX, game->currentPieceY + 1, game->currentPieceType, game->currentPieceRotation)) {
                    game->currentPieceY++;
                }
                break;
            }
            case (sf::Keyboard::X) : {
                while(board->isMovementPossible(game->currentPieceX, game->currentPieceY + 1, game->currentPieceType, game->currentPieceRotation)) {
                    game->currentPieceY++;
                }
                board->storePiece(game->currentPieceX, game->currentPieceY, game->currentPieceType, game->currentPieceRotation);

                if(board->isGameOver()) {
                    io->window->close();
                }
                game->createNewPiece();
                break;
            }
            case (sf::Keyboard::Z) : {
                if(board->isMovementPossible(game->currentPieceX, game->currentPieceY, game->currentPieceType, (game->currentPieceRotation + 1) % 4)) {
                    game->currentPieceRotation = (game->currentPieceRotation + 1) % 4;
                }
                break;
            }
        }

        long timePassed = clock.getElapsedTime().asMilliseconds();
        if((timePassed - time) > waitTime) {
            if(board->isMovementPossible(game->currentPieceX, game->currentPieceY + 1, game->currentPieceType, game->currentPieceRotation)) {
                game->currentPieceY++;
                time = timePassed;
            } else {
                board->storePiece(game->currentPieceX, game->currentPieceY, game->currentPieceType, game->currentPieceRotation);
                if(board->isGameOver()) {
                    io->window->close();
                }
                game->createNewPiece();
            }
        }
    }
    return 0;
}
