#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "Beholder.h"
#include "Player.h"
#include "Text.h"
#include "BeholderBullet.h"
#include "assets.h"
#include <iostream>
namespace fs = std::filesystem;
using namespace std;

class Game {
    int playerReloaded = 0;
    double playerRateOfFire = 5;
    double beholderReloaded = 0;
    Text levelText;
    Text hpText;
    Text attackText;
    Text speedText;
    Text dexText;
    Text vitText;
    string stringLevel;
    string stringHp;
    string stringAttack;
    string stringSpeed;
    string stringDex;
    string stringVit;
    sf::Texture inventoryTexture;
    sf::RectangleShape inventory = sf::RectangleShape(sf::Vector2f(180, 134));
    sf::Texture fireDaggerTexture;
    sf::Sprite fireDagger;
    sf::RectangleShape levelBar = sf::RectangleShape(sf::Vector2f(180, 20));
    sf::RectangleShape hpBar = sf::RectangleShape(sf::Vector2f(180, 20));
    sf::RectangleShape miniMap = sf::RectangleShape(sf::Vector2f(200,200));
    sf::Texture playerArrowTexture;
    sf::Sprite playerArrow;
public:
    vector<Beholder> beholders;
    vector<PlayerBullet> playerBullets;

    Game(fs::path assets);
    void looping(sf::RectangleShape &background, Window &window1, Player &player1, sf::Texture &playerBulletTexture,
                 sf::Texture &beholderBulletTexture, sf::Texture &beholderTexture, fs::path assets);
};
#endif //SPACEINVADERS_GAME_H
