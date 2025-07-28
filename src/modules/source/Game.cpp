#include <SFML/Graphics.hpp>
#include "../Game.hpp"

Maker::Game::Game(const std::string& windowTitle, const int& width, const int& height) {
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }
}