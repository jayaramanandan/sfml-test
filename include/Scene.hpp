#ifndef SCENE_HPP
#define SCENE_HPP

#include "aliases.hpp"

namespace builder {
    class Scene {
        private:
            SpritesArray sprites;
            ShapesArray uiElements;

        public:
            virtual ~Scene() = default;

            [[nodiscard]] SpritesArray& getSprites();
            [[nodiscard]] ShapesArray& getShapes();

            static void initiateEntity(const SpritePtr& sprite_ptr);
            static void renderEntity(const SpritePtr& sprite_ptr);

            void initiateEntities() const;
            void renderEntities() const;

            template <class T, typename... Args>
            std::shared_ptr<T> addEntity(Args&&... args);

    };
}

#include "Scene.tpp"

#endif
