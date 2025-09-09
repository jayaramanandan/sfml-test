#include <iostream>
#include <cmath>
#include "Entities/Animator.hpp"

void builder::Animator::setState(const std::string& animationName) {
    this->getDrawable().setTextureRect(this->animations.at(animationName).frames[0]);
}

void builder::Animator::playAnimation(const std::string& animationName, const float delay) {
    if (!this->animations.contains(animationName)) throw std::invalid_argument("No animation named: '" + animationName + "'");

    auto* animation = &this->animations.at(animationName);

    if(const int index = static_cast<int>(animation->clock.getElapsedTime().asSeconds() / delay); index < animation->frames.size()) {
        this->getDrawable().setTextureRect(animation->frames[index]);
    } else {
        animation->clock.restart();
    }
}

void builder::Animator::resetAnimation(const std::string& animationName) {
        this->animations.at(animationName).clock.restart();
}

void builder::Animator::addAnimation(const std::string& name, const std::vector<std::array<int, 4>>& frames) {
    if (frames.empty()) {
        throw std::invalid_argument("Cannot have 0 frames");
    }

    Animation animation;
    animation.frames.reserve(frames.size());

    for (const auto& frame : frames) {
        animation.frames.emplace_back(frame[0], frame[1], frame[2], frame[3]);
    }

    this->animations.insert(std::make_pair(name, animation));
};

void builder::Animator::addAnimation(const std::string& name, const std::vector<std::array<int, 2>>& frames, const int frameSize[2]) {
    if (frames.empty()) {
        throw std::invalid_argument("Cannot have 0 frames");
    }

    if (frames.empty()) {
        throw std::invalid_argument("Cannot have 0 frames");
    }

    Animation animation;
    animation.frames.reserve(frames.size());

    for (const auto& frame : frames) {
        animation.frames.emplace_back(frame[0], frame[1], frameSize[0], frameSize[1]);
    }

    this->animations.insert(std::make_pair(name, animation));
}

void builder::Animator::deleteAnimation(const std::string& name) {
    this->animations.erase(name);
}

void builder::Animator::startAnimationClocks() {
    for(auto& animation: this->animations) {
        animation.second.clock.restart();
    }
}
