#ifndef SCENE_TPP
#define SCENE_TPP

#include "Scene.hpp"

#include <type_traits>
#include "Entities/Sprite.hpp"

namespace builder {
    template<class T>
    void Scene::addEntity(T& entity) {
        if constexpr (std::is_base_of_v<Sprite, T>) {
            sprites.insert(&entity);
        }
    }

}

#endif
