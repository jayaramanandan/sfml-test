#include "../../include/GameManager/GameManager.hpp"

#include <iostream>
#include <filesystem>

namespace builder {
    WindowPtr GameManager::window;
    ScenesArray GameManager::scenes;
    int GameManager::currentSceneIndex = 0;
    WindowDetails GameManager::windowDetails;
    Dictionary<sf::Texture> GameManager::textures;
    bool GameManager::breakLoop = false;

    WindowPtr GameManager::getWindow() {
        return window;
    }

    void GameManager::createWindow(const WindowDetails& details) {
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(details.width, details.height), details.windowTitle);
        windowDetails = details;
    }

    ScenePtr GameManager::getCurrentScene() {
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

    void GameManager::setSpriteTextures(const std::string& directoryPath) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(directoryPath)) {
            if(const std::string texturePath = entry.path().string(); !textures.contains(texturePath) && entry.is_regular_file()) {
                sf::Texture spriteTexture;

                if(!spriteTexture.loadFromFile(texturePath)) {
                    std::cerr << "Unable to load texture: " << texturePath << "\n\n";
                }

                textures.insert({texturePath, spriteTexture});
            }
        }
    }

    sf::Texture& GameManager::getSpriteTexture(const std::string& texturePath) {
        return textures.at(texturePath);
    }

    void GameManager::run() {
        const ScenePtr currentScene = getCurrentScene();
        if (currentScene == nullptr) throw std::invalid_argument("Current Scene cannot be nullptr");

        currentScene->initiateEntities();

        while (!breakLoop && window->isOpen()) {
            sf::Event event{};
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) window->close();

                currentScene->renderEntityEvents(event);
            }

            window->clear();

            currentScene->updateEntities();

            window->display();
        }

        if (breakLoop) {
            breakLoop = false;
            run();
        }
    }


}