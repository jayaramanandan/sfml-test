#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <SFML/Graphics.hpp>

namespace builder {
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Animator {
        private:
            std::unordered_map<std::string, Animation> animations;
        
        public:
            virtual ~Animator() = default;
        
            virtual sf::Sprite* getSfSprite() = 0;
            
            void startAnimation(const std::string& animationName);
            void startAnimation(const std::string& animationName, const float& speed);

            void addAnimation(const std::string& name, const int frames[][4], const int& framesLength);
            void addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]);

            void deleteAnimation(std::string& name);

            void startAnimationClocks() const;
    };
}

#endif