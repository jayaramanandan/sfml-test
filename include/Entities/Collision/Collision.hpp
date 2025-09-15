#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SFML/Graphics.hpp"
#include "../Entity/Entity.hpp"

namespace builder {
    template <ValidType T>
    class Collision : public Entity<T>, Updatable {
        public:

            ~Collision() override = default;

            bool isColliding(const SpritePtr& sprite_ptr);
    };

    using SpriteCollision = Collision<sf::Sprite>;
    using ShapeCollision = Collision<sf::Shape>;
}

#include "Collision.tpp"

#endif
