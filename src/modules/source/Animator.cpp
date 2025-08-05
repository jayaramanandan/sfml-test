#include "../Animator.hpp"

void builder::Animator::startAnimation(const std::string& animationName) {
    this->getSfSprite()->setTextureRect(this->animations.at(animationName).frames[0]);
}

void builder::Animator::startAnimation(const std::string& animationName, const float& speed) {
    builder::Animation animation = this->animations.at(animationName);

    const int index = std::floor(
        animation.clock.getElapsedTime().asSeconds() / speed
    );

    if(index < animation.frames.size()) {
        this->getSfSprite()->setTextureRect(animation.frames[index]);
    }
}

void builder::Animator::addAnimation(const std::string& name, const int frames[][4], const int& framesLength) {
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
};

void builder::Animator::addAnimation(const std::string& name, const int frames[][2], const int& framesLength, const int frameSize[2]) {
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

void builder::Animator::deleteAnimation(std::string& name) {
    this->animations.erase(name);
}

void builder::Animator::startAnimationClocks() {
    for(auto& pair : this->animations) {
        pair.second.clock.restart();
    }
}