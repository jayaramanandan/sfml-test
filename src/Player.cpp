#include <string>
#include "Player.hpp"

Player::Player() {}

void Player::init() {
    this->setTexturePath("/workspaces/sfml-test/build/assets/Bowl.png");

     std::cout << this->getTexturePath() << std::endl;

    const int size[2] = {16, 16};
    const int frames[4][2] = {{0, 0}, {16, 0}, {32, 0}, {48, 0}};
    this->addAnimation("idle", frames, 4, size);

    this->setSize(10.0f, 10.0f);
    this->setPosition(200.0f, 200.0f);
}

void Player::update() {
    this->startAnimation("idle", 1);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "hello" << std::endl;
    }
}