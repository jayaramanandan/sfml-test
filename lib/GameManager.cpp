#include "GameManager.hpp"
#include <iostream>

namespace builder {
    WindowPtr GameManager::window;
    ScenesArray GameManager::scenes;
    int GameManager::currentSceneIndex = 0;
    WindowDetails GameManager::windowDetails;
    Dictionary<sf::Texture> GameManager::textures;
    bool GameManager::usingCache = false;
    bool GameManager::breakLoop = false;

    WindowPtr& GameManager::getWindow() {
        return window;
    }

    void GameManager::createWindow(const WindowDetails& details) {
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(details.width, details.height), details.windowTitle);
        windowDetails = details;
    }

    ScenePtr& GameManager::getCurrentScene() {
        return scenes[currentSceneIndex];
    }

    void GameManager::setCurrentScene(const int& currentSceneIndexValue) {
        currentSceneIndex = currentSceneIndexValue;
        breakLoop = true;
    }


    WindowDetails& GameManager::getWindowDetails() {
        return windowDetails;
    }

    void GameManager::setFrameRateDetails(const int& actualFrameRate, const int& observedFrameRate) {
        windowDetails.actualFrameRate = actualFrameRate;
        windowDetails.actualFrameRate = observedFrameRate;
    }

    void GameManager::addSpriteTexture(const SpritePtr& sprite_ptr) {
        if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

        std::string texturePath = sprite_ptr->getTexturePath();

        if(!textures.contains(texturePath)) { // checks to see if the texture path has already been stored
            sf::Texture spriteTexture;

            if(!spriteTexture.loadFromFile(texturePath)) {
                std::cerr << "Unable to load texture: " << texturePath << "\n\n";
            }

            textures.insert({texturePath, spriteTexture});
        }

        sprite_ptr->getDrawable().setTexture(textures.at(texturePath));
    }

    void GameManager::useCache() {
        usingCache = true;
    }

    void GameManager::run() {
        const ScenePtr currentScene = getCurrentScene();
        if (currentScene == nullptr) throw std::invalid_argument("Current Scene cannot be nullptr");

        currentScene->initiateEntities();

        while (!breakLoop && window->isOpen()) {
            Event event{};
            while (window->pollEvent(event)) {
                if (event.type == Event::Closed) window->close();
            }

            window->clear();

            currentScene->renderEntities();

            window->display();
        }

        if (breakLoop) {
            breakLoop = false;
            run();
        }
    }


}