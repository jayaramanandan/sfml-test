#include "StartButton.hpp"

StartButton::StartButton() : Button(40, 20) {}

void StartButton::init() {
    this->setPosition(20, 20);
    this->getDrawable().setFillColor(sf::Color::Magenta);
}

void StartButton::onClick() {
    builder::GameManager::setCurrentScene(1);
}