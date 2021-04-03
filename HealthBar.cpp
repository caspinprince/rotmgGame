#include "Player.h"
#include "HealthBar.h"
#include "Window.h"

void HealthBar::setHp(double x){
    hp = x;
}

void HealthBar::setMaxHp(double x){
    maxHp = x;
}

void HealthBar::drawBaseBar(sf::RenderWindow &window, float x, float y, double rotation, int xsize, int ysize){
    baseBar.setSize(sf::Vector2f(xsize, ysize));
    baseBar.setOrigin(0, ysize/2);
    baseBar.setPosition(x-sin((rotation+angleMod)*pi/180.0)*dist, y+cos((rotation+angleMod)*pi/180.0)*dist);
    baseBar.setFillColor(sf::Color(1,1,1));
    window.draw(baseBar);
}

void HealthBar::updateHealthBar(float x, float y, double rotation, int xsize, int ysize){
    healthBar.setSize(sf::Vector2f(xsize*hp/maxHp, ysize));
    healthBar.setPosition(x-sin((rotation+angleMod-1.8)*pi/180.0)*(dist-1.5), y+cos((rotation+angleMod-1.8)*pi/180.0)*(dist-1.5));
    healthBar.setOrigin(0, ysize/2);
    healthBar.setFillColor(sf::Color(((maxHp-hp)/maxHp)*255, hp/maxHp*255, 0));
}

void HealthBar::drawHealthBar(sf::RenderWindow &window){
    window.draw(healthBar);
}

void HealthBar::setDist(double x){
    dist = x;
}

void HealthBar::setAngleMod(double x){
    angleMod = x;
}

