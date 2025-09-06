#ifndef COLLISION_TPP
#define COLLISION_TPP

#include "Collision.hpp"
#include "GameManager.hpp"

namespace builder {
    template<ValidType T>
    EntityModule Collision<T>::getModule() {
        return EntityModule::Collision;
    }

    template<ValidType T>
    void Collision<T>::setIsClicking(const bool& newValue) {
        this->clicking = newValue;
    }

    template<ValidType T>
    bool Collision<T>::isColliding(Sprite &sprite) {
        return this->getDrawable().getGlobalBounds().intersects(
            sprite.getDrawable().getGlobalBounds()
        );
    }

    template<ValidType T>
    bool Collision<T>::mouseHovering() {
        const sf::Vector2i mousePos = sf::Mouse::getPosition(*GameManager::getWindow());
        return this->getDrawable().getGlobalBounds().contains(
            static_cast<float>(mousePos.x),
            static_cast<float>(mousePos.y)
        );

        return false;
    }

    template<ValidType T>
    bool Collision<T>::isClicking() const {
        return this->clicking;
    }

    template<ValidType T>
    bool Collision<T>::leftMouseDown() {
        return this->mouseHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }

}

#endif