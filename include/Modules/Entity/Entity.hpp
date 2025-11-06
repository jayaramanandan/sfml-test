#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SFML/Graphics.hpp"

namespace builder {
    template <class T>
    concept ValidType = std::is_same_v<T, sf::Sprite> || std::is_base_of_v<sf::Shape, T>;
    template <ValidType T>
    class Entity {
        public:
            virtual ~Entity() = default;

            virtual T& getDrawable() = 0;

            virtual void init() = 0;
            virtual void pollEvent(sf::Event& event) = 0;
            virtual void update() = 0;
    };

    using SpriteEntity = Entity<sf::Sprite>;
    using ShapeEntity = Entity<sf::Shape>;
}

#endif
