#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "../utility/Dictionary.hpp"

namespace builder {
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Animator : Entity<sf::Sprite> {
        private:
            Dictionary<Animation> animations{};
        
        public:
            void startAnimation(const std::string& animationName);
            void startAnimation(const std::string& animationName, const float& speed);

            void addAnimation(const std::string& name, const int frames[][4], const int& framesLength);
            void addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]);

            void deleteAnimation(std::string& name);

            void startAnimationClocks() const;
    };
}

#endif