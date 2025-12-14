#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include "Modules/Motion/Motion.hpp"
#include "Modules/Collision/Collision.hpp"

namespace builder {
    class Button : public ShapeMotion, public ShapeCollision {
        private:
            sf::RectangleShape buttonRect;

        public:
            Button(const float& width, const float& height);

            bool isTouchingMouse();

            sf::RectangleShape& getDrawable() override;

<<<<<<< HEAD
=======
            void pollEvent(sf::Event& event) override;
>>>>>>> be58acab964884cb2bbe1c8d5dec536fc33f5530
            void update() override;

            
            virtual void onHover();
            virtual void onClick();
            virtual void onMouseDown();
    };
}

#endif
