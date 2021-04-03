#include "BeholderBullet.h"
#include "Player.h"


BeholderBullet::BeholderBullet(int dist, int spd, sf::Texture &beholderBulletTexture, Player &player, Window &window, double xpos, double ypos, double angleMod, int i){
    damage = 120;
    range = dist;
    bulletSpeed = spd;
    bullet.setTexture(beholderBulletTexture);
    bullet.setPosition(xpos,ypos);
    bullet.setOrigin(sf::Vector2f(bullet.getTexture()->getSize().x * 0.5,bullet.getTexture()->getSize().y * 0.5));
    angleShot = atan2(player.getPosition().y - bullet.getPosition().y,
                      player.getPosition().x- bullet.getPosition().x );
    bullet.setRotation((angleShot*180/3.1415)+angleMod*i);
}

int BeholderBullet::getDamage(){
    return damage;
}
