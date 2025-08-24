#include "BowlGame.hpp"

BowlGame::BowlGame(builder::WindowDetails& windowDetails, builder::FrameRateDetails& frameRateDetails) :
Game(windowDetails, frameRateDetails),
player(200, 200)
{
    this->run();
}

void BowlGame::initiateSprites() {
    this->initiateSprite(player);
}

void BowlGame::render() {
    this->renderSprite(player);
}
