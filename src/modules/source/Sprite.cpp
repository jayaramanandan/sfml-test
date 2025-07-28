#include <iostream>
#include "../Sprite.hpp"

Maker::Sprite::Sprite(const std::string& textureFilePath) {
    if(!this->texture.loadFromFile(textureFilePath)) {
        std::cerr << "Unable to load texture file: " << textureFilePath << std::endl;
    }

    this->sprite.setTexture(this->texture);
}