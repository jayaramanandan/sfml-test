#include "../include/UI/Button.hpp"

builder::Button::Button(const float& width, const float& height) :
buttonRect(sf::Vector2f(width, height)) {}

sf::RectangleShape* builder::Button::getDrawable() {
    return &this->buttonRect;
}

sf::Color builder::Button::getFillColour() const {
    return this->buttonRect.getFillColor();
}

void builder::Button::setFillColour(const sf::Color& colour) {
    this->buttonRect.setFillColor(colour);
}

void builder::Button::update() {
    if (this->mouseHovering()) this->onHover();
    // ReSharper disable once CppDFAConstantConditions
    // ReSharper disable once CppDFAUnreachableCode
    if (this->isClicking()) this->onClick();
    if (this->leftMouseDown()) this->onMouseDown();
}

void builder::Button::onHover() {}
void builder::Button::onMouseDown() {}
void builder::Button::onClick() {}