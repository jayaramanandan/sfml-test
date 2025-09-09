#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "utility/Dictionary.hpp"

namespace builder {
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Animator : Entity<sf::Sprite> {
        private:
            Dictionary<Animation> animations{};
        
        public:
            ~Animator() override = default;

            void setState(const std::string& animationName);
            void playAnimation(const std::string& animationName, float delay);
            void resetAnimation(const std::string& animationName);

            void addAnimation(const std::string& name, const std::vector<std::array<int, 4>>& frames);
            void addAnimation(const std::string& name, const std::vector<std::array<int, 2>>& frames, const int frameSize[2]);

            void deleteAnimation(const std::string& name);

            void startAnimationClocks();
    };
}

#endif