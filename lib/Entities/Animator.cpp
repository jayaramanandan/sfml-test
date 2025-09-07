#include <iostream>
#include <cmath>
#include "Entities/Animator.hpp"

void builder::Animator::setState(const std::string& animationName) {
    this->getDrawable().setTextureRect(this->animations.at(animationName).frames[0]);
}

void builder::Animator::playAnimation(const std::string& animationName, const float& delay) {
    if (!this->animations.contains(animationName)) throw std::invalid_argument("No animation named: '" + animationName + "'");

    auto* animation = &this->animations.at(animationName);

    const int index = std::floor(
        animation->clock.getElapsedTime().asSeconds() / delay
    );

    if(index < animation->frames.size()) {
        this->getDrawable().setTextureRect(animation->frames[index]);
    } else {
        animation->clock.restart();
    }
}

void builder::Animator::resetAnimation(const std::string& animationName) {
        this->animations.at(animationName).clock.restart();
}

void builder::Animator::addAnimation(const std::string& name, const int frames[][4], const int& framesLength) {
    if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.emplace_back(frames[i][0], frames[i][1], frames[i][2], frames[i][3]);
    }

    this->animations.insert(std::make_pair(name, animation));
};

void builder::Animator::addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]) {
        if(framesLength == 0) {
        std::cerr << "cannot have 0 frames" << "\n\n";
    }

    Animation animation;

    animation.frames = std::vector<sf::IntRect>();
    animation.clock = sf::Clock();

    for(int i = 0; i < framesLength; i++) {
        animation.frames.emplace_back(frames[i][0], frames[i][1], frameSize[0], frameSize[1]);
    }

    this->animations.insert(std::make_pair(name, animation));
}

void builder::Animator::deleteAnimation(std::string& name) {
    this->animations.erase(name);
}

void builder::Animator::startAnimationClocks() const {
    for(auto animation: this->animations) {
        animation.second.clock.restart();
    }
}
