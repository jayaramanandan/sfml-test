#ifndef MOTION_TPP
#define MOTION_TPP

#include <iostream>
#include "Motion.hpp"
#include "../utility/maths.hpp"

namespace builder {
    template <ValidType T>
    void Motion<T>::setFrameRateDetails(FrameRateDetails* details) {
        if(details->observedFrameRate > details->actualFrameRate) {
            std::cerr << "The observed frame rate is greater than the actual frame rate" << std::endl;
        }

        this->frameRateDetails = details;
        this->multiplicationFactor = static_cast<float>(this->frameRateDetails->observedFrameRate) / static_cast<float>(this->frameRateDetails->actualFrameRate);
    }

    template <ValidType T>
    sf::Vector2f Motion<T>::getOrigin() {
        return this->getDrawable()->getOrigin();
    }

    template <ValidType T>
    sf::Color Motion<T>::getColour() {
        return this->getDrawable()->getColor();
    }

    template <ValidType T>
    sf::Vector2f Motion<T>::getPosition() {
        return this->getDrawable()->getPosition();
    }

    template <ValidType T>
    float Motion<T>::getRotation() {
        return this->getDrawable()->getRotation();
    }

    template <ValidType T>
    sf::Vector2f Motion<T>::getScale() {
        return this->getDrawable()->getScale();
    }

    template <ValidType T>
    void Motion<T>::setOrigin(const float& x, const float& y) {
        this->getDrawable()->setOrigin(x, y);
    }

    template <ValidType T>
    void Motion<T>::setOriginToObjectCentre() {
        const sf::FloatRect boundaryBox = this->getDrawable()->getGlobalBounds();
        this->setOrigin(
            boundaryBox.width / 2,
            boundaryBox.height / 2
        );
    }

    template <ValidType T>
    void Motion<T>::setColour(const sf::Color& colour) {
        this->getDrawable()->setColor(colour);
    }

    template <ValidType T>
    void Motion<T>::setPosition(const float& x, const float& y) {
        this->getDrawable()->setPosition(x, y);
    }

    template <ValidType T>
    void Motion<T>::setRotation(const float& degrees) {
        this->getDrawable()->setRotation(degrees);
    }

    template <ValidType T>
    void Motion<T>::setScale(const float& x, const float& y) {
        this->getDrawable()->setScale(x, y);
    }

    template <ValidType T>
    void Motion<T>::move(const float& x, const float&y) {
        this->getDrawable()->move(x * this->multiplicationFactor, -y * multiplicationFactor);
    }

    template <ValidType T>
    void Motion<T>::moveInCurrentDirection(const float& distance) {
        const auto [x, y] = getComponents(distance, this->getRotation());
        this->move(x, y);
    }

    template <ValidType T>
    void Motion<T>::rotate(const float& degrees) {
        this->getDrawable()->rotate(degrees * this->multiplicationFactor);
    }

    template <ValidType T>
    void Motion<T>::scale(const float& x, const float& y) {
        this->getDrawable()->scale((x - 1) * this->multiplicationFactor + 1, (y - 1) * this->multiplicationFactor + 1);
    }
}

#endif