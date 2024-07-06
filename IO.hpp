#ifndef _IO_
#define _IO_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct IO {
    sf::RenderWindow* window;

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
