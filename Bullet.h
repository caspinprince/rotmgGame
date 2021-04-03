#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <vector>
#include <cmath>
#include <math.h>
#include <iostream>

class Bullet{
protected:
    sf::Sprite bullet;
    float dist = 0;
    float range;
    int bulletSpeed;
    int damage;
    float angleShot;
public:
    void reload(double xpos, double ypos);

    void shoot(sf::RenderWindow &window);

    void shoot(sf::RenderWindow &window, int bulletCount, double angleMod, int i);

    bool inRange();

    void draw(sf::RenderWindow &window);

    sf::FloatRect bounds();
};
#endif //SPACEINVADERS_BULLET_H
