#include "../Sprite.hpp"

builder::Sprite::Sprite() {}

builder::Sprite::Sprite(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}

std::string builder::Sprite::getTexturePath() const {
    return this->texturePath;
}

sf::Sprite* builder::Sprite::getSfSprite() {
    return &this->sprite;
}

void builder::Sprite::setSize(const float& x, const float& y) {
    this->sprite.setScale(x, y);
}

void builder::Sprite::setPosition(const float& x, const float& y) {
    this->sprite.setPosition(x, y);
}

void builder::Sprite::setTexturePath(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}