#ifndef GAMEMANAGER_TPP
#define GAMEMANAGER_TPP

#include <memory>
#include "GameManager.hpp"
#include "Scene.hpp"

namespace builder {
    template<class T>
    void GameManager::setCurrentScene() {
        if (std::is_base_of_v<Scene, T>) {
            currentScene = std::make_shared<T>();
        } else {
            throw std::invalid_argument("Current Scene must be derived from Scene");
        }
    }

}

#endif