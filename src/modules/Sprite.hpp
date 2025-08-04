#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

#ifndef SPRITE_H
#define SPRITE_H

namespace builder {
    struct Animation {
        std::vector<sf::IntRect> frames;
        sf::Clock clock;
    };

    class Sprite {
        private:
            std::string texturePath;
            sf::Sprite sprite;
            std::unordered_map<std::string, builder::Animation> animations;

        public:
            Sprite();
            Sprite(const std::string& textureFilePath);

            // customisable by user
            std::string getTexturePath() const;
            sf::Sprite* getSfSprite();

            void setSize(const float& x, const float& y);
            void setPosition(const float& x, const float& y);
            void setTexturePath(const std::string& textureFilePath);
            void startAnimation(const std::string& animationName, const float& speed);
            void startAnimation(const std::string& animationName);
            void addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]);
            void addAnimation(const std::string& name, const int frames[][4], const int& framesLength);
            void deleteAnimation(std::string& name);

            // inits
            void startAnimationClocks();

            virtual void init() = 0; // called before starting sfml game
            virtual void update() = 0; // where update code goes
    };
}

#endif