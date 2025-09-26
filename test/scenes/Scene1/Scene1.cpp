#include "Scene1.hpp"

#include "sprites/Player.hpp"

Scene1::Scene1() :
player1(200, 200),
player2(200, 300, player1)
{}

void Scene1::initiateEntities() {
    this->initiateEntity(player1);
    this->initiateEntity(player2);
}

void Scene1::updateEntities() {
    this->updateEntity(player1);
    this->updateEntity(player2);
}
