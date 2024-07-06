#ifndef _IO_
#define _IO_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct IO {

    sf::RenderWindow* window;

    IO();

    auto clearWindow() -> void;
    auto drawRectangle(int x, int y, int width, int height, sf::Color color) -> void;
    auto getScreenHeight() -> int;
    auto updateScreen() -> void;
    auto pollkey() -> int;
    auto getKey() -> int;
    auto isKeyDown(int pKey) -> int;
    auto initGraph() -> int;
};

#endif // _IO_
