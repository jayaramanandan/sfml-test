#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "modules/Game.hpp"
#include "modules/Sprite.hpp"

void maker::Sprite::update() {
    this->playAnimation("idle", 2);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "hello" << std::endl;
    }
}

int main() {
    maker::Sprite sprite("/workspaces/sfml-test/build/assets/Bowl.png");
    const int size[2] = {16, 16};
    const int frames[4][2] = {{0, 0}, {16, 0}, {32, 0}, {48, 0}};
    sprite.addAnimation("idle", frames, 4, size);
    sprite.playAnimation("idle", 2);
    sprite.setSize(10.0f, 10.0f);
    sprite.setPosition(200.0f, 200.0f);

    maker::Game game;
    game.addSprite(sprite);
    game.run("Bowl Catch", 800, 600);

    return 0;
}