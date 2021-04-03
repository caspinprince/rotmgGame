#include "PlayerBullet.h"
#include "Player.h"
#include "Window.h"

PlayerBullet::PlayerBullet(int dist, int spd, sf::Texture &playerBulletTexture, Player &player, Window &window) {
    damage = rand()%70+85;
    range = dist;
    bulletSpeed = spd;
    bullet.setTexture(playerBulletTexture);
    bullet.setPosition(player.getPosition().x,player.getPosition().y);
    bullet.setOrigin(sf::Vector2f(bullet.getTexture()->getSize().x * 0.5,bullet.getTexture()->getSize().y * 0.5));
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    angleShot = atan2(mousePosition.y - bullet.getPosition().y,
                      mousePosition.x - bullet.getPosition().x );
}

int PlayerBullet::getDamage(){
    return damage;
}