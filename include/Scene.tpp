#ifndef SCENE_TPP
#define SCENE_TPP

#include <memory>
#include <type_traits>
#include "Scene.hpp"


namespace builder {
    template<class T, typename... Args>
    std::shared_ptr<T> Scene::addEntity(Args&&... args) {
        auto entity_ptr = std::make_shared<T>(std::forward<Args>(args)...);

        if constexpr (std::is_base_of_v<SpriteEntity, T>) {
            this->sprites.insert(entity_ptr);
        } else if constexpr (std::is_base_of_v<ShapeEntity, T>) {
            this->uiElements.insert(entity_ptr);
        } else {
            static_assert(
                std::is_base_of_v<SpriteEntity, T> || std::is_base_of_v<ShapeEntity, T>,
                "T must derive from SpriteEntity or ShapeEntity"
            );
        }

        return entity_ptr;
    }

}

#endif
