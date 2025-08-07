#include "Motion.hpp"

builder::Motion::Motion(FrameRateDetails* details) {
    if(details->observedFrameRate > details->actualFrameRate) {
        std::cerr << "The observed frame rate is greater than the actual frame rate" << std::endl;
    }
    
    this->frameRateDetails = details;
    this->multiplicationFactor = this->frameRateDetails->observedFrameRate / (float) this->frameRateDetails->actualFrameRate;
}

sf::Vector2f builder::Motion::getOrigin() {
    return this->getSfSprite()->getOrigin();
}

sf::Color builder::Motion::getColour() {
    return this->getSfSprite()->getColor();
}

sf::Vector2f builder::Motion::getPosition() {
    return this->getSfSprite()->getPosition();
}

float builder::Motion::getRotation() {
    return this->getSfSprite()->getRotation();
}

sf::Vector2f builder::Motion::getScale() {
    return this->getSfSprite()->getScale();
}

void builder::Motion::setOrigin(const float& x, const float& y) {
    this->getSfSprite()->setOrigin(x, y);
}

void builder::Motion::setOriginToObjectCentre() {
    const sf::FloatRect boundaryBox = this->getSfSprite()->getGlobalBounds();
    this->setOrigin(
        boundaryBox.width / 2,
        boundaryBox.height / 2
    );
}

void builder::Motion::setColour(const sf::Color& colour) {
    this->getSfSprite()->setColor(colour);
}

void builder::Motion::setPosition(const float& x, const float& y) {
    this->getSfSprite()->setPosition(x, y);
}

void builder::Motion::setRotation(const float& degrees) {
    this->getSfSprite()->setRotation(degrees);
}

void builder::Motion::setScale(const float& x, const float& y) {
    this->getSfSprite()->setScale(x, y);
}

void builder::Motion::move(const float& x, const float&y) {
    this->getSfSprite()->move(x * this->multiplicationFactor, -y * multiplicationFactor);
}

void builder::Motion::moveInCurrentDirection(const float& distance) {
    const builder::Components components = builder::getComponents(distance, this->getRotation());
    this->move(components.x, components.y);
}

void builder::Motion::rotate(const float& degrees) {
    this->getSfSprite()->rotate(degrees * this->multiplicationFactor);
}

void builder::Motion::scale(const float& x, const float& y) {
    this->getSfSprite()->scale((x - 1) * this->multiplicationFactor + 1, (y-1) * this->multiplicationFactor + 1);
}