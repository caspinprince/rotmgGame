#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>
#include <ctime>
#include <chrono>
#include "Player.h"
#include "Window.h"
#include "Text.h"
#include "Game.h"
#include "assets.h"
using namespace std;


int main(int count, const char **args) {
    srand(time(NULL));
    //fs::path assets = fs::path(args[0]).parent_path() / "assets";

    if (count > 1) {
        assets = args[1];
    } else if (count > 0) {
        assets = fs::path(args[0]).parent_path() / "assets";
    } else {
        assets = "assets";
    }

    sf::Texture playerBulletTexture;
    playerBulletTexture.loadFromFile((assets / "redBullet.png").string());
    sf::Texture beholderBulletTexture;
    beholderBulletTexture.loadFromFile((assets / "beholderBullet.png").string());
    sf::Texture beholderTexture;
    beholderTexture.loadFromFile((assets / "beholder.png").string());


    Player player1(assets);
    player1.readData(assets);
    Window window1;
    Game thisGame(assets);

    thisGame.looping(window1.background, window1, player1, playerBulletTexture, beholderBulletTexture, beholderTexture, assets);
    return EXIT_SUCCESS;
}
