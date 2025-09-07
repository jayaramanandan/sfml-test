#include "Player.hpp"
#include "GameManager.hpp"

Player::Player(const float& x, const float& y) : Sprite("assets/Bowl.png") {
    this->setPosition(x, y);
}

Player::Player(const float &x, const float &y, const builder::SpritePtr& player2) : Sprite("assets/Bowl.png") {
    this->setPosition(x, y);
    this->player2 = player2;
}

sf::Sprite& Player::getDrawable() {
    return this->getSfSprite();
}


void Player::init() {
    constexpr int frames[1][4] = {{1, 1, 14, 5}};

    this->addAnimation("idle", frames, 1);
    this->setState("idle");

    this->setOriginToObjectCentre();
    this->setScale(10.0f, 10.0f);
}

void Player::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->rotate(1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->rotate(-1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->moveInCurrentDirection(1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->moveInCurrentDirection(-1);
    }


    if (this->player2 != nullptr && this->isColliding(this->player2)) {
        builder::GameManager::setCurrentScene(1);
    }

}