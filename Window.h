using namespace std;
#ifndef SPACEINVADERS_WINDOW_H
#define SPACEINVADERS_WINDOW_H

class Window: public sf::RenderWindow{
    int width = 1200;
    int height = 700;
public:
    sf::Texture windowTexture;
    sf::RectangleShape background = sf::RectangleShape (sf::Vector2f(5000, 5000));
    sf::RectangleShape background2 = sf::RectangleShape(sf::Vector2f(200,700));
    sf::View view1 = sf::View(sf::FloatRect(0,0, 1000, height));
    sf::View view2 = sf::View(sf::FloatRect(5.0/6.0,0, 200, height));
    Window();
};

#endif //SPACEINVADERS_WINDOW_H
