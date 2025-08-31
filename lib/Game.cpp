#include "../include/Game.hpp"
#include "GameManager.hpp"
#include "../include/Entities/Motion.hpp"
#include "../include/Entities/Animator.hpp"
#include "../include/Entities/Collision.hpp"

builder::Game::Game(const WindowDetails& windowDetails, const FrameRateDetails& frameRateDetails) :
window(sf::VideoMode(windowDetails.width, windowDetails.height), windowDetails.windowTitle) {
    GameManager::setGame(this);
    this->frameRateDetails.observedFrameRate = frameRateDetails.observedFrameRate;
    this->frameRateDetails.actualFrameRate = frameRateDetails.actualFrameRate;
}

builder::FrameRateDetails* builder::Game::getFrameRateDetails() {
    return &this->frameRateDetails;
}

sf::RenderWindow *builder::Game::getWindow() {
    return &this->window;
}

void builder::Game::initiateSprite(Sprite &sprite) {
    this->addSpriteTexture(sprite);
    sprite.init();

    if (const auto* sprite_ptr = dynamic_cast<Animator*>(&sprite)) {
        sprite_ptr->startAnimationClocks();
    }
    if (auto* sprite_ptr = dynamic_cast<SpriteMotion*>(&sprite)) {
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

void builder::Game::addClickListener(SpriteCollision* sprite) {
    this->clickListenerSprites.push_back(sprite);
}

void builder::Game::addClickListener(ShapeCollision* shape) {
    this->clickListenerShapes.push_back(shape);
}


void builder::Game::run() {
    this->window.setFramerateLimit(this->frameRateDetails.actualFrameRate);

    this->initiateSprites();

    while (this->window.isOpen()) {
        sf::Event event{};
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) this->window.close();

            for (const auto sprite : this->clickListenerSprites) {
                sprite->setIsClicking(
                    event.type == sf::Event::MouseButtonPressed &&
                    event.mouseButton.button == sf::Mouse::Left &&
                    sprite->mouseHovering()
                );
            }

            for (const auto shape : this->clickListenerShapes) {
                shape->setIsClicking(
                    event.type == sf::Event::MouseButtonPressed &&
                    event.mouseButton.button == sf::Mouse::Left &&
                    shape->mouseHovering()
                );
            }
        }

        this->window.clear();

        // draw and update
        this->render();

        this->window.display();
    }
}