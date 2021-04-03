#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Window.h"
#include "assets.h"

Window::Window(){
    create(sf::VideoMode(width, height), "Realm of the Content God");
    setFramerateLimit(60);
    windowTexture.loadFromFile((assets / "rock.jpg").string());
    windowTexture.setRepeated(true);
    background.setTexture(&windowTexture);
    background.setTextureRect({0, 0, 5000, 5000});
    background2.setFillColor(sf::Color(54,54,54));
    background2.setOutlineColor(sf::Color(25,25,25));
    background2.setOutlineThickness(-5);
    view1.zoom(0.9);
    view1.setCenter(2000, 2000);
    view1.setSize(1000,height);
    view2.setSize(200, height);
}