#include <SFML/Graphics.hpp>

#ifndef SPRITE_H
#define SPRITE_H

namespace maker {
    class Sprite {
        private:
            std::string texturePath;
            sf::Sprite sprite;

        public:
            Sprite(const std::string& textureFilePath);
            std::string getTexturePath() const;
            sf::Sprite getSfSprite() const;
            void setRect(const sf::Vector2u& startingPos, const sf::Vector2u& size);
            void setSize(const sf::Vector2f& sizeVector);
            void setSpriteTexture(const sf::Texture& texture);
    };
}

#endif