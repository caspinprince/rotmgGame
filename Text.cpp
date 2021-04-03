#include "Text.h"

void Text::drawText(const string &text, int textSize, int xValue, int yValue, sf::Color color){
    setString(text);
    setCharacterSize(textSize);
    setFillColor(color);
    setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
    setPosition(xValue, yValue);
    setStyle(sf::Text::Bold);
}

Text::Text(){
    font.loadFromFile((assets / "roboto.ttf").string());
    setFont(font);
}

