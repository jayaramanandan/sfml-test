#include <iostream>
#include <SFML/Graphics.hpp>
#include "modules/Game.hpp"

void moveShape(sf::Shape& shape) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.setPosition(shape.getPosition() + sf::Vector2f(1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.setPosition(shape.getPosition() + sf::Vector2f(-1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.setPosition(shape.getPosition() + sf::Vector2f(0, -1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.setPosition(shape.getPosition() + sf::Vector2f(0, 1));
    }
}

int main() {
    /*
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Texture bowlTexture;
    if(!bowlTexture.loadFromFile("/workspaces/sfml-test/build/assets/Bowl.png")) {
        std::cout << "error in loading bowl sprite texture" << std::endl;
    }
    sf::Sprite bowl(bowlTexture);
    bowl.setTextureRect(sf::IntRect(0, 0, 16, 16));
    bowl.setScale(10.0f, 10.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(bowl);

        window.display();
    }
    */

    Maker::Game game("Bowl Catch", 800, 600);

    return 0;
}