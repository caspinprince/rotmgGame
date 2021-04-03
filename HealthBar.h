#ifndef SPACEINVADERS_HEALTHBAR_H
#define SPACEINVADERS_HEALTHBAR_H
#include <SFML/Graphics.hpp>
#include <math.h>

class HealthBar: public sf::RectangleShape{
protected:
    double hp;
    double maxHp = 1500;
    double pi = 2*acos(0.0);
    double dist;
    double angleMod;

public:
    sf::RectangleShape baseBar;
    sf::RectangleShape healthBar;

    void setHp(double x);

    void setMaxHp(double x);

    void drawBaseBar(sf::RenderWindow &window, float x, float y, double rotation, int xsize, int ysize);

    void updateHealthBar(float x, float y, double rotation, int xsize, int ysize);

    void drawHealthBar(sf::RenderWindow &window);

    void setDist(double x);

    void setAngleMod(double x);
};

#endif //SPACEINVADERS_HEALTHBAR_H
