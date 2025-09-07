#include "Entities/Sprite.hpp"

builder::Sprite::Sprite(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}

std::string builder::Sprite::getTexturePath() const {
    return this->texturePath;
}

sf::Sprite& builder::Sprite::getSfSprite() {
    return this->sprite;
}

void builder::Sprite::setTexturePath(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}