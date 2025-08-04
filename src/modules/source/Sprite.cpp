#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../Sprite.hpp"

maker::Sprite::Sprite() {}

maker::Sprite::Sprite(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}

std::string maker::Sprite::getTexturePath() const {
    return this->texturePath;
}

sf::Sprite maker::Sprite::getSfSprite() const {
    return this->sprite;
}

void maker::Sprite::setSize(const float& x, const float& y) {
    this->sprite.setScale(x, y);
}

void maker::Sprite::setPosition(const float& x, const float& y) {
    this->sprite.setPosition(x, y);
}

void maker::Sprite::setTexturePath(const std::string& textureFilePath) {
    this->texturePath = textureFilePath;
}

void maker::Sprite::startAnimation(const std::string& animationName, const float& speed) {
    maker::Animation animation = this->animations.at(animationName);

    const int index = std::floor(
        animation.clock.getElapsedTime().asSeconds() / speed
    );

    if(index < animation.frames.size()) {
        this->sprite.setTextureRect(animation.frames[index]);
    }
}

void maker::Sprite::startAnimation(const std::string& animationName) {
    this->sprite.setTextureRect(this->animations.at(animationName).frames[0]);
}

void maker::Sprite::setSpriteTexture(const sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void maker::Sprite::addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]) {
    if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    maker::Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.push_back(sf::IntRect(frames[i][0], frames[i][1], frameSize[0], frameSize[1]));
    }

    this->animations.insert(std::make_pair(name, animation));
}

void maker::Sprite::addAnimation(const std::string& name, const int frames[][4], const int& framesLength) {
        if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    maker::Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.push_back(sf::IntRect(frames[i][0], frames[i][1], frames[i][2], frames[i][3]));
    }

    this->animations.insert(std::make_pair(name, animation));
}

void maker::Sprite::deleteAnimation(std::string& name) {
    this->animations.erase(name);
}

void maker::Sprite::startAnimationClocks() {
    for(auto& pair : this->animations) {
        pair.second.clock.restart();
    }
}