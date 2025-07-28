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

void maker::Game::run(const std::string& windowTitle, const int& width, const int& height) const {
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::vector<maker::Sprite>::iterator sprite_ptr;
        for (auto sprite_ptr = this->sprites.begin(); sprite_ptr != this->sprites.end(); ++sprite_ptr) {
            window.draw(sprite_ptr->getSfSprite());
        }

        window.display();
    }
}