#ifndef SPACEINVADERS_BEHOLDER_H
#define SPACEINVADERS_BEHOLDER_H
#include "HealthBar.h"
#include "PlayerBullet.h"
#include "BeholderBullet.h"

using namespace std;

class Player;
class Window;

class Beholder{
    int hp = 1500;
    sf::Sprite beholder;
    vector<BeholderBullet> beholderBullets;

public:
    HealthBar healthbar;

    Beholder(Player &player, sf::Texture &beholderTexture);

    bool checkDeath();

    void setRotation(int angle);

    bool bulletHit(PlayerBullet playerBullets, Player &player);

    void shoot(Window &window, Player &player);

    bool activated(Player &player);

    void draw(sf::RenderWindow &window, Player &player);

    int getHp();

    void setHp(int x);

    void follow(Player &player);

    int getXPos();

    int getYPos();

    void createBullet(sf::Texture &beholderBulletTexture, Player &player, Window &window);
};

#endif //SPACEINVADERS_BEHOLDER_H
