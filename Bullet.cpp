#include "Player.h"
#include "HealthBar.h"
#include "Window.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "BeholderBullet.h"
#include "Beholder.h"
#include "Game.h"

void Bullet::reload(double xpos, double ypos){
    bullet.setPosition(xpos, ypos);
}

void Bullet::shoot(sf::RenderWindow &window){
    bullet.move(cos(angleShot) * bulletSpeed, sin(angleShot) * bulletSpeed);
    dist += hypot(cos(angleShot) * bulletSpeed, sin(angleShot) * bulletSpeed);
}

void Bullet::shoot(sf::RenderWindow &window, int bulletCount, double angleMod, int i){
    bullet.move(cos(angleShot+(angleMod*3.1415/180)*i) * bulletSpeed, sin(angleShot+(angleMod*3.1415/180)*i) * bulletSpeed);
    dist += hypot(cos(angleShot+(angleMod*3.1415/180)*i) * bulletSpeed, sin(angleShot+(angleMod*3.1415/180)*i) * bulletSpeed);
}

bool Bullet::inRange(){
    return dist<range;
}

void Bullet::draw(sf::RenderWindow &window){
    window.draw(bullet);
}

sf::FloatRect Bullet::bounds(){
    return bullet.getGlobalBounds();
}

