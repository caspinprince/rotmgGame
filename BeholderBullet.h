#ifndef SPACEINVADERS_BEHOLDERBULLET_H
#define SPACEINVADERS_BEHOLDERBULLET_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Window.h"

class Player;

class BeholderBullet: public Bullet{
public:
    bool hit = false;
    BeholderBullet(int dist, int spd, sf::Texture &beholderBulletTexture, Player &player, Window &window, double xpos, double ypos, double angleMod, int i);
    int getDamage();
};

#endif //SPACEINVADERS_BEHOLDERBULLET_H
