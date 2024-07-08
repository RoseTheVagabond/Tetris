#include "IO.hpp"
#include <cstdlib> // For exit()

IO::IO() {
    initGraph();
}

IO::~IO() {
}

void IO::clearWindow() {
    window->clear(sf::Color(0, 0, 0));
}

void IO::drawRectangle(int x, int y, int width, int height, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    window->draw(rectangle);
}

int IO::getScreenHeight() {
    return window->getSize().y;
}

void IO::updateScreen() {
    window->display();
}

int IO::pollkey() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed)
            return event.key.code;
        if (event.type == sf::Event::Closed)
            exit(3);
    }
    return -1;
}

int IO::getKey() {
    sf::Event event;
    while (true) {
        window->waitEvent(event);
        if (event.type == sf::Event::KeyPressed)
            break;
        if (event.type == sf::Event::Closed)
            exit(3);
    }
    return event.key.code;
}

int IO::isKeyDown(int pKey) {
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(pKey));
}

int IO::initGraph() {
    // Create a new window using unique_ptr
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), "Tetris");
    return 0;
}
