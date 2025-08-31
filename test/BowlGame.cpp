#include "BowlGame.hpp"

BowlGame::BowlGame(builder::WindowDetails& windowDetails, builder::FrameRateDetails& frameRateDetails) :
Game(windowDetails, frameRateDetails),
player(200, 200, &player2),
player2(200, 340)
{}

void BowlGame::initiateSprites() {
    this->initiateSprite(player);
    this->initiateSprite(player2);
}

void BowlGame::render() {
    this->renderSprite(player);
    this->renderSprite(player2);
}
