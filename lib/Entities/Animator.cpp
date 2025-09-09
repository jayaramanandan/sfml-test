#include "Entities/Animator.hpp"

#include <iostream>
#include <cmath>

namespace builder {
    void Animator::setState(const std::string& animationName) {
        this->getDrawable().setTextureRect(this->animations.at(animationName).frames[0]);
    }

    void Animator::playAnimation(const std::string& animationName, const float delay) {
        if (!this->animations.contains(animationName)) throw std::invalid_argument("No animation named: '" + animationName + "'");

        auto* animation = &this->animations.at(animationName);

        if (const int index = static_cast<int>(animation->clock.getElapsedTime().asSeconds() / delay); index < animation->frames.size()) {
            this->getDrawable().setTextureRect(animation->frames[index]);
        } else {
            animation->clock.restart();
        }
    }

    void Animator::resetAnimation(const std::string& animationName) {
            this->animations.at(animationName).clock.restart();
    }

    void Animator::addAnimation(const std::string& name, const Frames& frames) {
        if (frames.empty()) {
            throw std::invalid_argument("Cannot have 0 frames");
        }

        Animation animation;
        animation.frames.reserve(frames.size());

        for (const auto& frame : frames) {
            animation.frames.emplace_back(frame[0], frame[1], frame[2], frame[3]);
        }

        this->animations.insert(std::make_pair(name, animation));
    }

    void Animator::addAnimation(const std::string& name, const ConsistentFrames& frames, const int frameSize[2]) {
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

    void Animator::deleteAnimation(const std::string& name) {
        this->animations.erase(name);
    }

    void Animator::startAnimationClocks() {
        for (auto& animation: this->animations) {
            animation.second.clock.restart();
        }
    }
}