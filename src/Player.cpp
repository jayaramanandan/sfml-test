#include "Player.hpp"

Player::Player(builder::FrameRateDetails* frameRateDetails) :
builder::Sprite("assets/Bowl.png"),
builder::Motion(frameRateDetails) {}

sf::Sprite* Player::getSfSprite() {
    return Sprite::getSfSprite();
}

void Player::init() {
    constexpr int frames[1][4] = {{1, 1, 14, 5}};
    this->addAnimation("idle", frames, 1);
    this->startAnimation("idle");

    this->setOriginToObjectCentre();
    this->setPosition(100, 100);
    this->setScale(10.0f, 10.0f);
}

void Player::update() {
    this->startAnimation("idle", 1);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->rotate(5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->rotate(-5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->moveInCurrentDirection(5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->moveInCurrentDirection(-5);
    }
}