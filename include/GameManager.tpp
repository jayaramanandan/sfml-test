#ifndef GAMEMANAGER_TPP
#define GAMEMANAGER_TPP

#include <memory>
#include "GameManager.hpp"
#include "Scene.hpp"

namespace builder {
    template<class T, typename... Args>
    void GameManager::addScene(Args&&... args) {
        if (std::is_base_of_v<Scene, T>) {
            scenes.push_back(std::make_shared<T>(std::forward<Args>(args)...));
        } else {
            throw std::invalid_argument("Current Scene must be derived from Scene");
        }
    }

}

#endif