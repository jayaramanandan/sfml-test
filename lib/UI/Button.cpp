#include "UI/Button.hpp"

builder::Button::Button(const float& width, const float& height) :
buttonRect(sf::Vector2f(width, height)) {}

sf::RectangleShape& builder::Button::getDrawable() {
    return this->buttonRect;
}

sf::Color builder::Button::getFillColour() const {
    return this->buttonRect.getFillColor();
}

void builder::Button::setFillColour(const sf::Color& colour) {
    this->buttonRect.setFillColor(colour);
}

void builder::Button::update() {
}

void builder::Button::onHover() {}
void builder::Button::onMouseDown() {}
void builder::Button::onClick() {}