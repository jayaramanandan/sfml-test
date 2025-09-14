#include "Scene1.hpp"

#include "sprites/Player.hpp"

Scene1::Scene1() :
player1(200, 200),
player2(200, 400, player1)
{
    this->addEntity(player1);
    this->addEntity(player2);
}