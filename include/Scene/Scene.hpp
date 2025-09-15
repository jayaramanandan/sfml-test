#ifndef SCENE_HPP
#define SCENE_HPP

#include "../aliases.hpp"
#include "EntityStorage/EntityStore.hpp"
#include "Entities/Sprite/Sprite.hpp"

namespace builder {
    class Scene {
        private:
            EntityStore<Sprite> spritesStore;
            EntityStore<sf::Shape> uiElementsStore;

        public:
            virtual ~Scene() = default;

            [[nodiscard]] EntityStore<Sprite>& getSpritesStore();
            [[nodiscard]] EntityStore<sf::Shape>& getUiElementsStore();

            static void initiateEntity(const SpritePtr& sprite_ptr);
            static void renderEntity(const SpritePtr& sprite_ptr);

            void initiateEntities();
            void renderEntityEvents(sf::Event& event);//
            void renderEntities();

            template <class T>
            void addEntity(T& entity);

    };
}

#include "Scene.tpp"

#endif
