#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#ifndef ANIMATION_H
#define ANIMATION_H

namespace builder {
    
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Animation {
        private:
            std::unordered_map<std::string, builder::Animation> animations;
        
        public:
            virtual sf::Sprite getSfSprite() const = 0;
            
            void startAnimation(const std::string& animationName, const float& speed);
            void startAnimation(const std::string& animationName);

    };
}

#endif