#include "UI/Button.hpp"

builder::Button::Button(const float& width, const float& height) :
buttonRect(sf::Vector2f(width, height)) {}

sf::RectangleShape& builder::Button::getDrawable() {
    return this->buttonRect;
}

void builder::Button::pollEvent(sf::Event& event) {
    if (
        const sf::Vector2i mousePos = sf::Mouse::getPosition(*GameManager::getWindow());
        event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Button::Left &&
        this->getDrawable().getGlobalBounds().contains(
            static_cast<float>(mousePos.x),
            static_cast<float>(mousePos.y)
        )
    ) {
        this->onClick();
    }
}


void builder::Button::update() {
    if (const sf::Vector2i mousePos = sf::Mouse::getPosition(*GameManager::getWindow());
        this->getDrawable().getGlobalBounds().contains(
            static_cast<float>(mousePos.x),
            static_cast<float>(mousePos.y)
        )
    ) {
        this->onHover();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) this->onMouseDown();
    }
}

void builder::Button::onHover() {}
void builder::Button::onMouseDown() {}
void builder::Button::onClick() {}