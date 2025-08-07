#include <iostream>
#include "SFML/Graphics.hpp"
#include "../utility//FrameRateDetails/FrameRateDetails.hpp"
#include "../utility/maths/maths.hpp"

#ifndef MOTION_H
#define MOTION_H

namespace builder {
    class Motion {
        private:
            builder::FrameRateDetails* frameRateDetails;
            float multiplicationFactor;
        
        public:
            Motion(FrameRateDetails* details);

            virtual sf::Sprite* getSfSprite() = 0;

            sf::Vector2f getOrigin();
            sf::Color getColour();
            sf::Vector2f getPosition();
            float getRotation();
            sf::Vector2f getScale();

            void setOrigin(const float& x, const float& y);
            void setOriginToObjectCentre();
            void setColour(const sf::Color& colour);
            void setPosition(const float& x, const float& y);
            void setRotation(const float& degrees);
            void setScale(const float& x, const float& y);

            void move(const float& x, const float& y);
            void moveInCurrentDirection(const float& distance);
            void rotate(const float& degrees);
            void scale(const float& x, const float& y);
    };
}

#endif

// pi/180 = 1