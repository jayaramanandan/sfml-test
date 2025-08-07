#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../Animator/Animator.hpp"

#ifndef SPRITE_H
#define SPRITE_H

namespace builder {
    class Sprite {
        private:
            std::string texturePath;
            sf::Sprite sprite;
            std::unordered_map<std::string, builder::Animation> animations;

        public:
            Sprite(const std::string& textureFilePath);

            // customisable by user
            std::string getTexturePath() const;
            sf::Sprite* getSfSprite();
            
            void setTexturePath(const std::string& textureFilePath);

            virtual void init() = 0; // called after window renders
            virtual void update() = 0; // where update code goes
    };
}

#endif