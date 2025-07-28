#include <SFML/Graphics.hpp>

#ifndef SPRITE_H
#define SPRITE_H

namespace Maker {
    class Sprite {
        private:
            sf::Texture texture;
            sf::Sprite sprite;

        public:
            Sprite(const std::string& textureFilePath);
            void setRect(const sf::Vector2u& startingPos, const sf::Vector2u& size) const;
            void setSize(const sf::Vector2f& sizeVector) const;
    };
}

#endif