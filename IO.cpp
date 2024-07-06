#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


struct IO {

    sf::RenderWindow* window;

    IO() {
        initGraph();
    }

    auto clearWindow() -> void {
        window->clear(sf::Color(0, 0, 0));
    }

    auto drawRectangle(int x, int y, int width, int height, sf::Color color) -> void {
        sf::RectangleShape rectangle(sf::Vector2f(width, height));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(color);
        window->draw(rectangle);
    }

    auto getScreenHeight() -> int {
        return window->getSize().y;
    }

    auto updateScreen() -> void {
        window->display();
    }

    auto pollkey() -> int {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                return event.key.code;
            if (event.type == sf::Event::Closed)
                exit(3);
        }
        return -1;
    }

    auto getKey() -> int {
        sf::Event event;
        while (true)
        {
            window->waitEvent(event);
            if (event.type == sf::Event::KeyPressed)
                break;
            if (event.type == sf::Event::Closed)
                exit(3);
        }
        return event.key.code;
    }

    auto isKeyDown(int pKey) -> int {
        return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(pKey));
    }

    auto initGraph()-> int {
        // Create a new window
        window = new sf::RenderWindow(sf::VideoMode(640, 480), "Tetris");
        return 0;
    }

};