#include "UI/Button.hpp"

builder::Button::Button(const float& width, const float& height) :
buttonRect(sf::Vector2f(width, height)) {}

bool builder::Button::isTouchingMouse() {
    const sf::Vector2i mousePos = sf::Mouse::getPosition(*GameManager::getWindow());

    return this->getDrawable().getGlobalBounds().contains(
        static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y)
    );
}

sf::RectangleShape& builder::Button::getDrawable() {
    return this->buttonRect;
}

void builder::Button::pollEvent(sf::Event& event) {
    if (
        event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Button::Left &&
        this->isTouchingMouse()
    ) {
        this->onClick();
    }
}

void builder::Button::update() {
    if (this->isTouchingMouse()) {
        this->onHover();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) this->onMouseDown();
    }
}

void builder::Button::onHover() {}
void builder::Button::onMouseDown() {}
void builder::Button::onClick() {}