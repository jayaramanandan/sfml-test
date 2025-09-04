#include "../include/GameManager.hpp"

namespace builder {
    sf::RenderWindow* GameManager::window;
    ScenePtr GameManager::currentScene;

    sf::RenderWindow* GameManager::getRenderWindow() {
        return window;
    }

    void GameManager::setRenderWindow(sf::RenderWindow& windowValue) {
        window = &windowValue;
    }

    ScenePtr& GameManager::getCurrentScene() {
        return currentScene;
    }

}