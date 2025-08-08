#ifndef SPRITE_H
#define SPRITE_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Animator.hpp"

namespace builder {
    class Sprite {
        private:
            std::string texturePath;
            sf::Sprite sprite;
            std::unordered_map<std::string, Animation> animations;

        public:
            explicit Sprite(const std::string& textureFilePath);
            virtual ~Sprite() = default;

            // customisable by user
            std::string getTexturePath() const;
            virtual sf::Sprite* getSfSprite();
            
            void setTexturePath(const std::string& textureFilePath);

            virtual void init() = 0; // called after window renders
            virtual void update() = 0; // where update code goes
    };
}

#endif