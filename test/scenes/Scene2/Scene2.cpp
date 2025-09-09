#include "Scene2.hpp"
#include "../Scene1/sprites/Player.hpp"

Scene2::Scene2() :
player(200, 200)
{
    this->addEntity<Player>(player);
}
