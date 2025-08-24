#include "SFML/Graphics.hpp"
#include "../include/Game.hpp"
#include "Motion.hpp"
#include "../include/Animator.hpp"

builder::Game::Game(const std::string& windowTitle, const int& width, const int& height, const int& observedFrameRate, const int& actualFrameRate) :
window(sf::VideoMode(width, height), windowTitle) {
    this->frameRateDetails.observedFrameRate = observedFrameRate;
    this->frameRateDetails.actualFrameRate = actualFrameRate;
}

builder::FrameRateDetails* builder::Game::getFrameRateDetails() {
    return &this->frameRateDetails;
}

void builder::Game::initiateSprite(Sprite &sprite) {
    this->addSpriteTexture(sprite);
    sprite.init();

    if (const auto* sprite_ptr = dynamic_cast<Animator*>(&sprite)) {
        sprite_ptr->startAnimationClocks();
    }
    if (auto* sprite_ptr = dynamic_cast<Motion*>(&sprite)) {
        sprite_ptr->setFrameRateDetails(&this->frameRateDetails);
    }
}

void builder::Game::renderSprite(Sprite& sprite) {
    sprite.update();

    const sf::FloatRect bounds = sprite.getSfSprite()->getGlobalBounds();
    sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
    myRect.setFillColor(sf::Color::Red);
    myRect.setPosition(bounds.getPosition());

    this->window.draw(myRect);

    this->window.draw(*sprite.getSfSprite());
}

void builder::Game::addSpriteTexture(Sprite& sprite) {
    std::string texturePath = sprite.getTexturePath();

    if(!this->textures.contains(texturePath)) { // checks to see if the texture path has already been stored
        sf::Texture spriteTexture;

        if(!spriteTexture.loadFromFile(texturePath)) {
            std::cerr << "Unable to load texture: " << texturePath << "\n\n";
        }

        this->textures.insert({texturePath, spriteTexture});
        
    }

    sprite.getSfSprite()->setTexture(this->textures.at(texturePath));
}

void builder::Game::run() {
    this->window.setFramerateLimit(this->frameRateDetails.actualFrameRate);

    this->initiateSprites();

    while (this->window.isOpen()) {
        sf::Event event{};
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }

        this->window.clear();

        // draw and update
        this->render();


        /*
        for(auto& sprite_ptr : this->sprites) {
            sf::FloatRect bounds = sprite_ptr->getSfSprite()->getGlobalBounds();
            sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
            myRect.setFillColor(sf::Color::Red);
            myRect.setPosition(bounds.getPosition());

            window.draw(myRect);



            window.draw(*sprite_ptr->getSfSprite());
        }*/

        this->window.display();
    }
}