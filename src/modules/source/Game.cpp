#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Game.hpp"

void maker::Game::addSprite(maker::Sprite& sprite) {
    std::string texturePath = sprite.getTexturePath();

    if(this->textures.find(texturePath) == this->textures.end()) { // checks to see if the texture path has already been stored
        sf::Texture spriteTexture;

        if(!spriteTexture.loadFromFile(texturePath)) {
            std::cerr << "Unable to load texture: " << texturePath << "\n\n";
        }

        this->textures.insert({texturePath, spriteTexture});
        
    }

    sprite.setSpriteTexture(this->textures.at(texturePath));
    this->sprites.push_back(sprite);
}

void maker::Game::run(const std::string& windowTitle, const int& width, const int& height) {
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // updates
        for(auto& sprite : this->sprites) {
            sprite.update();
        }

        window.clear();

        // draw
        for(auto& sprite : this->sprites) {
            window.draw(sprite.getSfSprite());
        }

        window.display();
    }
}