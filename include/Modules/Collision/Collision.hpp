#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "aliases.hpp"
#include "SFML/Graphics.hpp"
#include "../Entity/Entity.hpp"

namespace builder {
    template <ValidType T>
    class Collision : public Entity<T> {
        public:
            ~Collision() override = default;

            bool isColliding(SpritePtr sprite_ptr);
    };

    using SpriteCollision = Collision<sf::Sprite>;
    using ShapeCollision = Collision<sf::Shape>;
}

#include "Collision.tpp"

#endif
