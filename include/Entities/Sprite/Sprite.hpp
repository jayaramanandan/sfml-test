#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.hpp"

namespace builder {
    class Sprite : public SpriteEntity {
        private:
            std::string texturePath;
            sf::Sprite sprite;

        public:
            explicit Sprite(const std::string& textureFilePath);

            sf::Sprite& getSfSprite();

            // customisable by user
            std::string getTexturePath() const;
            
            void setTexturePath(const std::string& textureFilePath);
    };
}

#endif