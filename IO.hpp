#ifndef _IO_
#define _IO_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory> // Include memory header for smart pointers

struct IO {
    std::unique_ptr<sf::RenderWindow> window; // Smart pointer for sf::RenderWindow

    IO();
    ~IO(); // Destructor to clean up resources

    void clearWindow();
    void drawRectangle(int x, int y, int width, int height, sf::Color color);
    int getScreenHeight();
    void updateScreen();
    int pollkey();
    int getKey();
    int isKeyDown(int pKey);
    int initGraph();
};

#endif // _IO_
