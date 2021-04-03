#ifndef SPACEINVADERS_TEXT_H
#define SPACEINVADERS_TEXT_H
using namespace std;
#include <SFML/Graphics.hpp>
#include <iostream>
#include "assets.h"


namespace fs = std::filesystem;

class Text: public sf::Text{
public:

    sf::Font font;

    Text();

    void drawText(const string &text, int textSize, int xValue, int yValue, sf::Color color);

};

#endif //SPACEINVADERS_TEXT_H
