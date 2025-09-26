#include "../../include/Entities/Sprite/Sprite.hpp"

namespace builder {
    std::string& Sprite::getTexturePath() {
        return this->texturePath;
    }

    sf::Sprite& Sprite::getSfSprite() {
        return this->sprite;
    }

    void Sprite::setTexturePath(const std::string& textureFilePath) {
        this->texturePath = textureFilePath;
    }
}