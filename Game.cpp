#include "Game.h"

Game::Game(fs::path assets){
    inventoryTexture.loadFromFile((assets / "inventory.png").string());
    inventory.setTexture(&inventoryTexture);
    inventory.setOrigin(inventory.getSize().x/2, inventory.getSize().y/2);
    fireDaggerTexture.loadFromFile((assets / "fireDagger.png").string());
    fireDagger.setTexture(fireDaggerTexture);
    playerArrowTexture.loadFromFile((assets / "playerArrow.png").string());
    playerArrow.setTexture(playerArrowTexture);
}

void Game::looping(sf::RectangleShape &background, Window &window1, Player &player1, sf::Texture &playerBulletTexture,
                   sf::Texture &beholderBulletTexture, sf::Texture &beholderTexture, fs::path assets){
    for(int i = 0; i<15; i++){
        beholders.emplace_back(player1, beholderTexture);
    }
    while (window1.isOpen() && !player1.checkDeath()) {
        sf::Event event = {};
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window1.close();
            }
        }


        window1.setView(window1.view1);
        window1.view1.setViewport(sf::FloatRect(0, 0, 5.0 / 6.0, 1));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (playerReloaded >= 60) {
                playerBullets.emplace_back(200, 10, playerBulletTexture, player1, window1);
                playerReloaded = 0;
            }
            playerReloaded += (playerRateOfFire + player1.dex * 0.0867);
        }

        if (beholderReloaded >= 60) {
            for (int i = 0; i < beholders.size(); i++) {
                beholders[i].createBullet(beholderBulletTexture, player1, window1);
            }
            beholderReloaded = 0;
        }
        beholderReloaded += 1.5;


        player1.playerhealthbar.setMaxHp(player1.getMaxHp());

        window1.draw(background);
        player1.regen();
        player1.levelUp();
        player1.draw(window1, player1);
        player1.movement(window1.view1, *this);


        for (int i = 0; i < beholders.size(); i++) {
            if (beholders[i].activated(player1)) {
                beholders[i].follow(player1);
            }
            beholders[i].healthbar.setHp(beholders[i].getHp());
            if (!beholders[i].checkDeath()) {
                beholders[i].draw(window1, player1);
                beholders[i].shoot(window1, player1);
            } else if (beholders[i].checkDeath()) {
                player1.xp += 150;
                beholders.erase(beholders.begin() + i);
                beholders.emplace_back(player1, beholderTexture);
            }
        }


        for (int j = 0; j < beholders.size(); j++) {
            for (int i = 0; i < playerBullets.size(); i++) {
                if (!playerBullets[i].inRange() || beholders[j].bulletHit(playerBullets[i], player1)) {
                    playerBullets.erase(playerBullets.begin() + i);
                }
            }
        }

        for (int i = 0; i < playerBullets.size(); i++) {
            playerBullets[i].shoot(window1);
            playerBullets[i].draw(window1);
        }


        window1.setView(window1.view2);
        window1.view2.setViewport(sf::FloatRect(5.0 / 6.0, 0, 1.0 / 6.0, 1));

        stringLevel = to_string(player1.level);
        levelText.drawText("Level " + stringLevel, 15, 100, 220, sf::Color::White);

        levelBar.setOrigin(levelBar.getSize().x / 2, levelBar.getSize().y / 2);
        levelBar.setPosition(100, 224);
        levelBar.setFillColor(sf::Color(0, 99, 0));

        stringHp = to_string((int)player1.getHp());
        hpText.drawText("HP: " + stringHp, 15, 100, 250, sf::Color::White);

        hpBar.setOrigin(hpBar.getSize().x / 2, hpBar.getSize().y / 2);
        hpBar.setPosition(100, 254);
        hpBar.setFillColor(sf::Color::Red);

        stringAttack = to_string(player1.attack);
        attackText.drawText("ATT - " + stringAttack, 12, 60, 290, sf::Color(170, 170, 170));
        stringSpeed = to_string(player1.speed);
        speedText.drawText("SPD - " + stringSpeed, 12, 60, 305, sf::Color(170, 170, 170));
        stringDex = to_string(player1.dex);
        dexText.drawText("DEX - " + stringDex, 12, 140, 290, sf::Color(170, 170, 170));
        stringVit = to_string(player1.vit);
        vitText.drawText("VIT - " + stringVit, 12, 140, 305, sf::Color(170, 170, 170));

        miniMap.setPosition(0,0);
        miniMap.setFillColor(sf::Color::Black);
        inventory.setPosition(100, 400);
        fireDagger.setPosition(9, 333);

        playerArrow.setPosition((player1.getPosition().x/5000.0)*200,(player1.getPosition().y/5000.0)*200);
        playerArrow.setRotation(player1.getRotation());

        window1.draw(window1.background2);
        window1.draw(levelBar);
        window1.draw(hpBar);
        window1.draw(levelText);
        window1.draw(hpText);
        window1.draw(attackText);
        window1.draw(speedText);
        window1.draw(dexText);
        window1.draw(vitText);
        window1.draw(inventory);
        window1.draw(fireDagger);
        window1.draw(miniMap);
        window1.draw(playerArrow);


        window1.display();
        window1.clear();
        if (player1.checkDeath()) {
            player1.resetData(assets);
        }
    }
    if(!player1.checkDeath()) {
        player1.storeData(assets);
    }
}
