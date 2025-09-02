#include "BowlGame.hpp"
#include "scenes/Scene1/Scene1.hpp"

BowlGame::BowlGame(builder::WindowDetails& windowDetails, builder::FrameRateDetails& frameRateDetails) :
Game(windowDetails, frameRateDetails) {
    Scene1 scene1;
    this->addScene("Scene1", &scene1);
    this->setCurrentScene("Scene1");
    this->run();
}
