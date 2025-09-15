#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <array>
#include <vector>
#include <SFML/Graphics.hpp>
#include "aliases.hpp"
#include "../Entity/Entity.hpp"
#include "Entities/Initialisable/Initialisable.hpp"
#include "Entities/Updatable/Updatable.hpp"
#include "utility/Dictionary.hpp"

namespace builder {
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Animator : Entity<sf::Sprite>, Initialisable, Updatable {
        private:
            Dictionary<Animation> animations{};
        
        public:
            ~Animator() override = default;

            void setState(const std::string& animationName);
            void playAnimation(const std::string& animationName, float delay);
            void resetAnimation(const std::string& animationName);

            void addAnimation(const std::string& name, const Frames& frames);
            void addAnimation(const std::string& name, const ConsistentFrames& frames, const int frameSize[2]);

            void deleteAnimation(const std::string& name);

            void startAnimationClocks();
    };
}

#endif