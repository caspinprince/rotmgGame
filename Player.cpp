#include "Player.h"
#include "Game.h"


Player::Player(fs::path assets){
    playerTexture.loadFromFile((assets / "rogue.png").string());
    setTexture(playerTexture);
    setScale(scale, scale);
    setPosition(2000,2000);
    setOrigin(sf::Vector2f(getTexture()->getSize().x * 0.5,getTexture()->getSize().y * 0.5));
    playerhealthbar.setMaxHp(maxHp);
    playerhealthbar.setAngleMod(37.9);
    playerhealthbar.setDist(57);
}

void Player::storeData(fs::path assets){
    ofstream myFile((assets / "playerData.txt").string());
    myFile << hp << "\n" << maxHp << "\n" << level << "\n" << attack << "\n" << speed << "\n" << dex << "\n" <<  vit << "\n" << xp;
    myFile.close();
}

void Player::readData(fs::path assets){
    int counter = 0;
    ifstream inputFile;
    inputFile.open((assets / "playerData.txt").string());
    while(counter<8 && inputFile >> playerData[counter]){
        counter++;
    }
    inputFile.close();
    hp = playerData[0];
    maxHp = playerData[1];
    level = playerData[2];
    attack = playerData[3];
    speed = playerData[4];
    dex = playerData[5];
    vit = playerData[6];
    xp = playerData[7];
    inputFile.close();
}

void Player::resetData(fs::path assets){
    ofstream myFile((assets / "playerData.txt").string());
    myFile << 150 << "\n" << 150 << "\n" << 1 << "\n" << 10 << "\n" << 15 << "\n" << 15 << "\n" <<  15 << "\n" << 0;
    myFile.close();
}

bool Player::inBounds(sf::View &view1){
    return (view1.getCenter().y>=-5 && view1.getCenter().y<=5005 && view1.getCenter().x>=-5 && view1.getCenter().x<+5005);
}

void Player::movement(sf::View &view1, Game &game){
    double diagonalMod = 1.0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                                                           sf::Keyboard::isKeyPressed(sf::Keyboard::D))){
            diagonalMod = 0.707;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::D))){
            diagonalMod = 0.707;
        }
        else{
            diagonalMod = 1.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && inBounds(view1)) {
            view1.move(diagonalMod * sin(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * -cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed));
            move(diagonalMod * sin(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * -cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            view1.move(diagonalMod * sin(view1.getRotation()*pi/180.0) * -10, diagonalMod * -cos(view1.getRotation()*pi/180.0) * -10);
            move(diagonalMod * sin(view1.getRotation()*pi/180.0) * -10, diagonalMod * -cos(view1.getRotation()*pi/180.0) * -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && inBounds(view1)) {
            view1.move(diagonalMod * -cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * -sin(view1.getRotation()*pi/180.0)*(4+0.07467*speed));
            move(diagonalMod * -cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * -sin(view1.getRotation()*pi/180.0)*(4+0.07467*speed));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            view1.move(diagonalMod * -cos(view1.getRotation()*pi/180.0) * -10, diagonalMod * -sin(view1.getRotation()*pi/180.0)*-10);
            move(diagonalMod * -cos(view1.getRotation()*pi/180.0) * -10, diagonalMod * -sin(view1.getRotation()*pi/180.0)*-10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && inBounds(view1)) {
            view1.move(diagonalMod * -sin(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed));
            move(diagonalMod * -sin(view1.getRotation()*pi/180.0) * (4+0.07467*speed), diagonalMod * cos(view1.getRotation()*pi/180.0) * (4+0.07467*speed));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            view1.move(diagonalMod * -sin(view1.getRotation()*pi/180.0) * -10, diagonalMod * cos(view1.getRotation()*pi/180.0) * -10);
            move(diagonalMod * -sin(view1.getRotation()*pi/180.0) *-10, diagonalMod * cos(view1.getRotation()*pi/180.0) * -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && inBounds(view1)) {
            view1.move(diagonalMod * cos((view1.getRotation())*pi/180.0) * (4+0.07467*speed), diagonalMod * sin((view1.getRotation())*pi/180.0) * (4+0.07467*speed));
            move(diagonalMod * cos((view1.getRotation())*pi/180.0) * (4+0.07467*speed), diagonalMod * sin((view1.getRotation())*pi/180.0) * (4+0.07467*speed));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            view1.move(diagonalMod * cos((view1.getRotation())*pi/180.0) * -10, diagonalMod * sin((view1.getRotation())*pi/180.0) * -10);
            move(diagonalMod * cos((view1.getRotation())*pi/180.0) * -10, diagonalMod * sin((view1.getRotation())*pi/180.0) * -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            view1.rotate(-2);
            rotate(-2);
            playerhealthbar.healthBar.rotate(-2);
            playerhealthbar.baseBar.rotate(-2);
            for(auto &x : game.beholders) {
                x.setRotation(-2);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            view1.rotate(2);
            rotate(2);
            playerhealthbar.healthBar.rotate(2);
            playerhealthbar.baseBar.rotate(2);
            for(auto &x : game.beholders) {
                x.setRotation(2);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            for(auto &x : game.beholders) {
                x.setRotation(-view1.getRotation());
            }
            view1.setRotation(0);
            setRotation(0);
            playerhealthbar.healthBar.setRotation(0);
            playerhealthbar.baseBar.setRotation(0);
        }
}

void Player::draw(sf::RenderWindow &window, Player &player){
    window.draw(player);
    playerhealthbar.drawBaseBar(window, player.getPosition().x, player.getPosition().y, player.getRotation(), 70, 8);
    player.playerhealthbar.setHp(player.getHp());
    playerhealthbar.updateHealthBar(player.getPosition().x, player.getPosition().y, player.getRotation(), 65, 6);
    playerhealthbar.drawHealthBar(window);
}

double Player::getHp(){
    return hp;
}

double Player::getMaxHp(){
    return maxHp;
}

void Player::setHp(int x){
    hp = x;
}

void Player::regen(){
    if(hp<maxHp) {
        hp += ((1+vit*0.24)/60.0);
    }
}

bool Player::checkDeath(){
    return hp<=0;
}

bool Player::bulletHit(BeholderBullet beholderbullets) {
    return (beholderbullets.bounds().intersects(getGlobalBounds()));
}

void Player::levelUp(){
    if(xp>=level*level*50) {
        level++;
        cout << level << endl;
        maxHp += rand() % 11 + 20;
        playerhealthbar.setMaxHp(maxHp);
        attack += rand() % 3;
        speed += rand() % 2 + 1;
        dex += rand() % 2 + 1;
        vit += rand() % 2;
    }
}


