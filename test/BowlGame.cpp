#include "BowlGame.h"

BowlGame::BowlGame() :
Game("Bowl Catch", 800, 600, 30, 60),
player(200, 200)
{
    this->run();
}

void BowlGame::initiateSprites() {
    std::cout << player.getTexturePath() << std::endl;
    this->initiateSprite(player);
}

void BowlGame::render() {
    this->renderSprite(player);
}
