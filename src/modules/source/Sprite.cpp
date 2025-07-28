#include <SFML/Graphics.hpp>
#include "../Sprite.hpp"

maker::Sprite::Sprite(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
    this->sprite.setPosition(200.0f, 200.0f);
    this->sprite.setScale(10.0f, 10.0f);
}

std::string maker::Sprite::getTexturePath() const {
    return this->texturePath;
}

sf::Sprite maker::Sprite::getSfSprite() const {
    return this->sprite;
}

void maker::Sprite::setSpriteTexture(const sf::Texture& texture) {
    this->sprite.setTexture(texture);
}