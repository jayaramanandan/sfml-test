#include <unordered_map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef SPRITE_H
#define SPRITE_H

namespace maker {
    class Sprite {
        private:
            std::string texturePath;
            sf::Sprite sprite;
            std::unordered_map<std::string, std::vector<sf::IntRect>> animations;
            std::unordered_map<std::string, sf::Clock> animationClocks;

        public:
            Sprite(const std::string& textureFilePath);

            std::string getTexturePath() const;
            sf::Sprite getSfSprite() const;

            void setSize(const float x, const float y);
            void setPosition(const float x, const float y);
            void playAnimation(const std::string animationName, const float speed);
            void playAnimation(const std::string animationName);
            void setSpriteTexture(const sf::Texture& texture);
            void addAnimation(const std::string name, const int frames[][2], const int framesLength, const int frameSize[2]);
            void addAnimation(const std::string name, const int frames[][4], const int framesLength);

            void init();
            void update(); // where update code goes
    };
}

#endif