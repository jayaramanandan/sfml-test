#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Sprite.hpp"

namespace builder {
    struct Listeners {
        bool hover = false;
        bool click = false;
        bool mouseDown = false;
    };

    template <ValidType T>
    class Collision : public Entity<T>{
        private:
            bool clicking = false;

        public:
            ~Collision() override = default;

            EntityModule getModule() override;

            void setIsClicking(const bool& newValue);

            bool isColliding(Sprite& sprite);
            bool mouseHovering();
            [[nodiscard]] bool isClicking() const;
            bool leftMouseDown();
    };

    using SpriteCollision = Collision<sf::Sprite>;
    using ShapeCollision = Collision<sf::Shape>;
}

#include "Collision.tpp"

#endif
