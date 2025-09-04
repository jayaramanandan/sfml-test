#ifndef BUTTON_H
#define BUTTON_H

#include "../Entities/Collision.hpp"
#include "SFML/Graphics.hpp"
#include "../Entities/Motion.hpp"

namespace builder {
    class Button : public ShapeMotion, public ShapeCollision {
        private:
            sf::RectangleShape buttonRect;

        public:
            Button(const float& width, const float& height);

            sf::RectangleShape& getDrawable() override;

            sf::Color getFillColour() const;
            void setFillColour(const sf::Color& colour);

            void update() override;

            virtual void onHover();
            virtual void onClick();
            virtual void onMouseDown();
    };
}

#endif
