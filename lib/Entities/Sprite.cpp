#include "../../include/Entities/Sprite/Sprite.hpp"

namespace builder {
    Sprite::Sprite(const std::string& textureFilePath) {
        this->texturePath = textureFilePath;
    }

    std::string Sprite::getTexturePath() const {
        return this->texturePath;
    }

    sf::Sprite& Sprite::getSfSprite() {
        return this->sprite;
    }

    void Sprite::setTexturePath(const std::string& textureFilePath) {
        this->texturePath = textureFilePath;
    }
}