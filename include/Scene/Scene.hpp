#ifndef SCENE_HPP
#define SCENE_HPP

#include "SFML/Graphics.hpp"

namespace builder {
    class Scene {
        public:
            virtual ~Scene() = default;

            template <typename T>
            void initiateEntity(T& entity);

            template <typename T>
            void pollEntityEvents(T& entity, sf::Event& event);

            template <typename T>
            void updateEntity(T& entity);

            virtual void initiateEntities() {};
            virtual void renderEntityEvents(sf::Event& event) {};
            virtual void updateEntities() {};

    };
}

#include "Scene.tpp"

#endif
