#include "../Game.hpp"

void builder::Game::addSprite(std::unique_ptr<builder::Sprite> sprite_ptr) {
    this->sprites.push_back(std::move(sprite_ptr));
}

void builder::Game::addSpriteTexture(const std::unique_ptr<builder::Sprite>& sprite_ptr) {
    std::string texturePath = sprite_ptr->getTexturePath();

    if(this->textures.find(texturePath) == this->textures.end()) { // checks to see if the texture path has already been stored
        sf::Texture spriteTexture;

        if(!spriteTexture.loadFromFile(texturePath)) {
            std::cerr << "Unable to load texture: " << texturePath << "\n\n";
        }

        this->textures.insert({texturePath, spriteTexture});
        
    }

    sprite_ptr->getSfSprite()->setTexture(this->textures.at(texturePath));
}

void builder::Game::run(const std::string& windowTitle, const int& width, const int& height) {
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle);

    // initialise sprites
    for(auto& sprite_ptr : this->sprites) {
        sprite_ptr->init();

        this->addSpriteTexture(std::move(sprite_ptr));

        sprite_ptr->startAnimationClocks();
    }
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // updates
        for(auto& sprite_ptr : this->sprites) {
            sprite_ptr->update();
        }

        window.clear();

        // draw
        for(auto& sprite_ptr : this->sprites) {
            window.draw(*sprite_ptr->getSfSprite());
        }

        window.display();
    }
}