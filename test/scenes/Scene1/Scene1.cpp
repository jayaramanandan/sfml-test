#include "Scene1.hpp"
#include "sprites/Player.hpp"

Scene1::Scene1() :
player1(200, 300),
player2(200, 400, player1)
{
    this->addEntity<Player>(player1);
    this->addEntity<Player>(player2);
}