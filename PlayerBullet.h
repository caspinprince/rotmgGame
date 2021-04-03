#ifndef SPACEINVADERS_PLAYERBULLET_H
#define SPACEINVADERS_PLAYERBULLET_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player;
class Window;

class PlayerBullet: public Bullet{
public:
    PlayerBullet(int dist, int spd, sf::Texture &playerBulletTexture, Player &player, Window &window);

    int getDamage();

};

#endif //SPACEINVADERS_PLAYERBULLET_H
