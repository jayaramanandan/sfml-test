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
            sf::RenderWindow* window{};
            Listeners listeners;
            bool clicking = false;

        public:
            void addHoverListener();
            void addClickListener();
            void addMouseDownListener();

            void setIsClicking(const bool& newValue);

            bool isColliding(Sprite& sprite);
            bool mouseHovering();
            [[nodiscard]] bool isClicking() const;
            bool leftMouseDown();
    };

    using SpriteCollision = Collision<sf::Sprite>;
    using ShapeCollision = Collision<sf::Shape>;
}

#include "Collsion.tpp"

#endif