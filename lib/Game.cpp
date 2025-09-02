#include "../include/Game.hpp"
#include "../include/Entities/Motion.hpp"
#include "../include/Entities/Animator.hpp"
#include "../include/Entities/Collision.hpp"
#include "../include/Scene.hpp"
#include "../include/WindowManager.hpp"

builder::Game::Game(const WindowDetails& windowDetails, const FrameRateDetails& frameRateDetails) :
window(sf::VideoMode(windowDetails.width, windowDetails.height), windowDetails.windowTitle) {
    WindowManager::setRenderWindow(window);
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
    if (this->scenes.empty()) {
        throw std::runtime_error("No scene has been added to the game");
    }
    if (this->scenes.contains(currentSceneName)) {
        return this->scenes.at(currentSceneName);
    }

    throw std::runtime_error("No scene with the name: '" + currentSceneName + "' has been added to the game");
}


void builder::Game::addSpriteTexture(const SpritePtr& sprite_ptr) {
    if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

    std::string texturePath = sprite_ptr->getTexturePath();

    if(!this->textures.contains(texturePath)) { // checks to see if the texture path has already been stored
        sf::Texture spriteTexture;

        if(!spriteTexture.loadFromFile(texturePath)) {
            std::cerr << "Unable to load texture: " << texturePath << "\n\n";
        }

        this->textures.insert({texturePath, spriteTexture});
        
    }

    sprite_ptr->getDrawable()->setTexture(this->textures.at(texturePath));
}

void builder::Game::initiateEntity(const SpritePtr& sprite_ptr) {
    if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

    this->addSpriteTexture(sprite_ptr); // continue here
    sprite_ptr->init();

    if (const auto* sprite = dynamic_cast<Animator*>(sprite_ptr.get())) {
        sprite->startAnimationClocks();
    }
    if (auto* sprite = dynamic_cast<SpriteMotion*>(sprite_ptr.get())) {
        sprite->setFrameRateDetails(this->getFrameRateDetails());
    }
}

void builder::Game::pollEntityEvents(const Events& event, const SpritePtr& sprite_ptr) {
    if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

    if (auto* sprite = dynamic_cast<SpriteCollision*>(sprite_ptr.get())) {
        sprite->setIsClicking(
            event.type == Events::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left &&
            sprite->mouseHovering()
        );
    }
}


void builder::Game::renderEntity(const SpritePtr& sprite_ptr) {
    if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

    sprite_ptr->update();

    if (sprite_ptr->getDrawable() == nullptr) throw std::runtime_error("Sprite has no drawable");

    const sf::FloatRect bounds = sprite_ptr->getDrawable()->getGlobalBounds();
    sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
    myRect.setFillColor(sf::Color::Red);
    myRect.setPosition(bounds.getPosition());
    this->getWindow()->draw(myRect);

    this->getWindow()->draw(*sprite_ptr->getDrawable());
}

void builder::Game::addScene(const std::string& sceneName, Scene* scene) {
    if (scene == nullptr) throw std::invalid_argument("Scene cannot be nullptr");

    this->scenes.insert_or_assign(sceneName, scene);
}

void builder::Game::setCurrentScene(const std::string& sceneName) {
    this->currentSceneName = sceneName;
}

void builder::Game::run() {
    this->window.setFramerateLimit(this->frameRateDetails.actualFrameRate);

    Scene* currentScene = this->getCurrentScene();

    if (currentScene == nullptr) throw std::invalid_argument("Current Scene cannot be nullptr");

    for (const auto& sprite_ptr : *currentScene->getSprites()) {
        this->initiateEntity(sprite_ptr);
    }

    while (this->window.isOpen()) {
        Events event{};
        while (this->window.pollEvent(event)) {
            if (event.type == Events::Closed) this->window.close();

            for (const auto& sprite_ptr : *currentScene->getSprites()) {
                pollEntityEvents(event, sprite_ptr);
            }
        }

        this->window.clear();

        // draw and update
        for (const auto& sprite_ptr : *currentScene->getSprites()) {
            this->renderEntity(sprite_ptr);
        }

        this->window.display();
    }
}