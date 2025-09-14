#ifndef GAMEMANAGER_TPP
#define GAMEMANAGER_TPP

#include "GameManager.hpp"

#include <memory>
#include "../Scene/Scene.hpp"

namespace builder {
    template<class T, typename... Args>
    void GameManager::addScene(Args&&... args) {
        static_assert(std::is_base_of_v<Scene, T>, "T must derive from Scene");
        scenes.push_back(std::make_shared<T>(std::forward<Args>(args)...));
    }

}

#endif