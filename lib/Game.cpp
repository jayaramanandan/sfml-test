#include "../include/Game.hpp"
#include "GameManager.hpp"
#include "../include/Entities/Motion.hpp"
#include "../include/Entities/Animator.hpp"
#include "../include/Entities/Collision.hpp"
#include "../include/Scene.hpp"

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

builder::Scene* builder::Game::getCurrentScene() const {
    return this->scenes.at(currentSceneName);
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

void builder::Game::addScene(const std::string& sceneName, Scene* scene) {
    this->scenes.insert_or_assign(sceneName, scene);
}

void builder::Game::run() {
    this->window.setFramerateLimit(this->frameRateDetails.actualFrameRate);

    Scene* currentScene = this->getCurrentScene();

    currentScene->initiateSprites();

    while (this->window.isOpen()) {
        Events event{};
        while (this->window.pollEvent(event)) {
            if (event.type == Events::Closed) this->window.close();

            for (const auto sprite : currentScene->getClickListenerSprites()) {
                sprite->setIsClicking(
                    event.type == Events::MouseButtonPressed &&
                    event.mouseButton.button == sf::Mouse::Left &&
                    sprite->mouseHovering()
                );
            }

            for (const auto shape : currentScene->getClickListenerShapes()) {
                shape->setIsClicking(
                    event.type == Events::MouseButtonPressed &&
                    event.mouseButton.button == sf::Mouse::Left &&
                    shape->mouseHovering()
                );
            }
        }

        this->window.clear();

        // draw and update
        currentScene->render();

        this->window.display();
    }
}