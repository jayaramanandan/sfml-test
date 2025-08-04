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

void builder::Sprite::startAnimation(const std::string& animationName, const float& speed) {
    builder::Animation animation = this->animations.at(animationName);

    const int index = std::floor(
        animation.clock.getElapsedTime().asSeconds() / speed
    );

    if(index < animation.frames.size()) {
        this->sprite.setTextureRect(animation.frames[index]);
    }
}

void builder::Sprite::startAnimation(const std::string& animationName) {
    this->sprite.setTextureRect(this->animations.at(animationName).frames[0]);
}

void builder::Sprite::addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]) {
    if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    builder::Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.push_back(sf::IntRect(frames[i][0], frames[i][1], frameSize[0], frameSize[1]));
    }

    this->animations.insert(std::make_pair(name, animation));
}

void builder::Sprite::addAnimation(const std::string& name, const int frames[][4], const int& framesLength) {
        if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    builder::Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.push_back(sf::IntRect(frames[i][0], frames[i][1], frames[i][2], frames[i][3]));
    }

    this->animations.insert(std::make_pair(name, animation));
}

void builder::Sprite::deleteAnimation(std::string& name) {
    this->animations.erase(name);
}

void builder::Sprite::startAnimationClocks() {
    for(auto& pair : this->animations) {
        pair.second.clock.restart();
    }
}