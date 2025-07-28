#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Sprite.hpp"

maker::Sprite::Sprite(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}

std::string maker::Sprite::getTexturePath() const {
    return this->texturePath;
}

sf::Sprite maker::Sprite::getSfSprite() const {
    return this->sprite;
}

void maker::Sprite::setSize(const float x, const float y) {
    this->sprite.setScale(x, y);
}

void maker::Sprite::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void maker::Sprite::playAnimation(std::string animationName, int speed) {
    for (const auto& frame : this->animations.at(animationName)) {
        this->sprite.setTextureRect(frame);
    }
}

void maker::Sprite::setSpriteTexture(const sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void maker::Sprite::addAnimation(const std::string name, const int frames[][2], const int framesLength, const int frameSize[2]) {
    if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    this->animations.insert(std::make_pair(name, std::vector<sf::IntRect>()));

    for(int i = 0; i < framesLength; i++) {
        this->animations.at(name).push_back(sf::IntRect(frames[i][0], frames[i][1], frameSize[0], frameSize[1]));
    }
}

void maker::Sprite::addAnimation(const std::string name, const int frames[][4], const int framesLength) {
    if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    this->animations.insert(std::make_pair(name, std::vector<sf::IntRect>()));

    for(int i = 0; i < framesLength; i++) {
        this->animations.at(name).push_back(sf::IntRect(frames[i][0], frames[i][1], frames[i][2], frames[i][3]));
    }
}