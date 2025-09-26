#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Modules/Entity/Entity.hpp"

namespace builder {
    class Sprite : public SpriteEntity {
        private:
            std::string texturePath;
            sf::Sprite sprite;

        public:
            sf::Sprite& getSfSprite();

            // customisable by user
            std::string& getTexturePath();
            
            void setTexturePath(const std::string& textureFilePath);
    };
}

#endif