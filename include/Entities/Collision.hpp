#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"

namespace builder {
    template <ValidType T>
    class Collision : public Entity<T>{
        public:
            ~Collision() override = default;

            virtual bool checkClicks();

            bool isColliding(const SpritePtr& sprite_ptr);
    };

    using SpriteCollision = Collision<sf::Sprite>;
    using ShapeCollision = Collision<sf::Shape>;
}

#include "Collision.tpp"

#endif
