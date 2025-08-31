#ifndef COLLISION_TPP
#define COLLISION_TPP

#include "Collision.hpp"
#include "Game.hpp"
#include "../GameManager.hpp"

namespace builder {
    template<ValidType T>
    void Collision<T>::addHoverListener() {
        this->listeners.hover = true;
    }

    template<ValidType T>
    void Collision<T>::addClickListener() {
        GameManager::getGame()->addClickListener(this);
        this->listeners.click = true;
    }

    template<ValidType T>
    void Collision<T>::addMouseDownListener() {
        this->listeners.mouseDown = true;
    }

    template<ValidType T>
    void Collision<T>::setIsClicking(const bool& newValue) {
        this->clicking = newValue;
    }

    template<ValidType T>
    bool Collision<T>::isColliding(Sprite &sprite) {
        return this->getDrawable()->getGlobalBounds().intersects(
            sprite.getSfSprite()->getGlobalBounds()
        );
    }

    template<ValidType T>
    bool Collision<T>::mouseHovering() {
        if (this->listeners.hover) {
            const sf::Vector2i mousePos = sf::Mouse::getPosition(*GameManager::getGame()->getWindow());
            return this->getDrawable()->getGlobalBounds().contains(
                static_cast<float>(mousePos.x),
                static_cast<float>(mousePos.y)
            );
        }

        return false;
    }

    template<ValidType T>
    bool Collision<T>::isClicking() const {
        return this->clicking;
    }

    template<ValidType T>
    bool Collision<T>::leftMouseDown() {
        return this->listeners.mouseDown && this->mouseHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }

}

#endif