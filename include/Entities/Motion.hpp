#ifndef MOTION_H
#define MOTION_H

#include "Entity.hpp"
#include "SFML/Graphics.hpp"
#include "../utility/FrameRateDetails.hpp"

namespace builder {
    template <ValidType T>
    class Motion : public Entity<T> {
        private:
            FrameRateDetails*frameRateDetails = nullptr;
            float multiplicationFactor = 1;
        
        public:
            ~Motion() override = default;

            EntityModule getModule() override;

            void setFrameRateDetails(FrameRateDetails* details);

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

    using SpriteMotion = Motion<sf::Sprite>;
    using ShapeMotion = Motion<sf::Shape>;
}

#include "Motion.tpp"

#endif