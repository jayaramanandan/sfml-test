#include "Player.hpp"
#include "../../../../include/GameManager.hpp"
#include "../../Scene2/Scene2.hpp"

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
    this->startAnimation("idle");

    this->setOriginToObjectCentre();
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


    if (this->player2 != nullptr && this->isColliding(*this->player2)) {
        builder::GameManager::setCurrentScene<Scene2>();
        std::cout << builder::GameManager::getCurrentScene().get()->getSprites().size() << "\n";
    }

}