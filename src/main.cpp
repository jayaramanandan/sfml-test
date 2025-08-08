#include <string>
#include <memory>
#include "../include/Game.hpp"
#include "Player.hpp"

int main() {
    builder::Game game(30, 60);
    game.addSprite(std::make_unique<Player>(game.getFrameRateDetails()));
    game.run("Bowl Catch", 800, 600);

    return 0;
}

//dawd