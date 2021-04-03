#include "Beholder.h"
#include "Player.h"

#include <iostream>
using namespace std;

Beholder::Beholder(Player &player, sf::Texture &beholderTexture){
    beholder.setTexture(beholderTexture);
    beholder.setPosition(rand()%5000+1,rand()%5000+1);
    beholder.setOrigin(sf::Vector2f(beholder.getTexture()->getSize().x * 0.5,beholder.getTexture()->getSize().y * 0.5));
    beholder.setRotation(player.getRotation());
    healthbar.setMaxHp(hp);
    healthbar.setDist(64);
    healthbar.setAngleMod(38.66);
    healthbar.healthBar.setRotation(player.getRotation());
    healthbar.baseBar.setRotation(player.getRotation());

}



bool Beholder::checkDeath(){
    return hp<=0;
}

void Beholder::setRotation(int angle) {
    beholder.rotate(angle);
    healthbar.healthBar.rotate(angle);
    healthbar.baseBar.rotate(angle);
}

bool Beholder::bulletHit(PlayerBullet playerBullets, Player &player) {
    if (playerBullets.bounds().intersects(beholder.getGlobalBounds()) && hp > 0) {
        hp -= playerBullets.getDamage()*(player.attack+25)/50;
        return true;
    }
}

void Beholder::createBullet(sf::Texture &beholderBulletTexture, Player &player, Window &window){
    if(activated(player)) {
        for (int i = 0; i < 5; i++) {
            beholderBullets.emplace_back(800, 6.5, beholderBulletTexture, player, window, beholder.getPosition().x,
                                         beholder.getPosition().y, 72, i);
        }
    }
}

void Beholder::shoot(Window &window, Player &player){
    for (int i = 0; i < beholderBullets.size(); i++) {
        if (beholderBullets[i].inRange() && activated(player) && !player.bulletHit(beholderBullets[i]) && !beholderBullets[i].hit){
            beholderBullets[i].shoot(window, 5, 72, i);
            beholderBullets[i].draw(window);
        }
        else if(beholderBullets[i].inRange() && player.bulletHit(beholderBullets[i]) && !beholderBullets[i].hit && player.getHp()>0){
            player.setHp(player.getHp()-beholderBullets[i].getDamage());
            beholderBullets[i].hit = true;
        }
    }
}

bool Beholder::activated(Player &player){
    double distanceToPlayer = hypot(beholder.getPosition().y - player.getPosition().y,
            beholder.getPosition().x - player.getPosition().x );
    return distanceToPlayer<800;
}

void Beholder::draw(sf::RenderWindow &window, Player &player){
        window.draw(beholder);
        healthbar.drawBaseBar(window, beholder.getPosition().x, beholder.getPosition().y, beholder.getRotation(),85, 10);
        healthbar.updateHealthBar(beholder.getPosition().x, beholder.getPosition().y, beholder.getRotation(), 80, 8);
        healthbar.drawHealthBar(window);
}

int Beholder::getHp(){
    return hp;
}

void Beholder::setHp(int x){
    hp = x;
}
void Beholder::follow(Player &player){
    float angleShot = atan2(beholder.getPosition().y - player.getPosition().y,
                            beholder.getPosition().x - player.getPosition().x );
    beholder.move(-cos(angleShot) * 2, -sin(angleShot) * 2);
}

int Beholder::getXPos(){
    return beholder.getPosition().x;
}

int Beholder::getYPos(){
    return beholder.getPosition().y;
}

