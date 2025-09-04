#include "BowlGame.hpp"

#include "GameManager.hpp"
#include "scenes/Scene1/Scene1.hpp"

BowlGame::BowlGame(builder::WindowDetails& windowDetails, builder::FrameRateDetails& frameRateDetails) :
Game(windowDetails, frameRateDetails) {
    builder::GameManager::setCurrentScene<Scene1>();
    builder::GameManager::setCurrentScene<Scene1>();

    this->run();
}
