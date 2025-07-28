#include <iostream>
#include <SFML/Graphics.hpp>
#include "modules/Game.hpp"
#include "modules/Sprite.hpp"

int main() {
    maker::Game game;
    maker::Sprite sprite("/workspaces/sfml-test/build/assets/Bowl.png");
    game.addSprite(sprite);
    
    game.run("Bowl Catch", 800, 600);

    return 0;
}