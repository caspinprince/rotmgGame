using namespace std;

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "HealthBar.h"

namespace fs = std::filesystem;

class BeholderBullet;
class Game;

class Player: public sf::Sprite{
    double scale = 0.3;
    sf::Texture playerTexture;
    double pi = 2*acos(0.0);
    double playerData[8];

protected:
    double hp;
    double maxHp;
public:
    int level = 1;
    int attack = 10;
    int speed = 15;
    int dex = 15;
    int vit = 15;
    int xp = 0;
    HealthBar playerhealthbar;
    Player(fs::path assets);
    void storeData(fs::path assets);
    void readData(fs::path assets);
    void resetData(fs::path assets);
    bool inBounds(sf::View &view1);
    void movement(sf::View &view1, Game &game);
    void draw(sf::RenderWindow &window, Player &player);
    double getHp();
    double getMaxHp();
    void setHp(int x);
    void regen();
    bool checkDeath();
    bool bulletHit(BeholderBullet beholderbullets);
    void levelUp();
};


#endif //SPACEINVADERS_PLAYER_H
