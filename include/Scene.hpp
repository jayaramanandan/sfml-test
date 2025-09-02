#ifndef SCENE_HPP
#define SCENE_HPP

#include "aliases.hpp"

namespace builder {
    class Scene {
        private:
            int sceneId = 0;
            SpritesArray sprites;
            ShapesArray uiElements;

        public:
            virtual ~Scene() = default;

            [[nodiscard]] SpritesArray* getSprites();
            [[nodiscard]] ShapesArray* getShapes();

            template <class T, typename... Args>
            std::shared_ptr<T> addEntity(Args&&... args);

    };
}

#include "Scene.tpp"

#endif
