#include "Scene2.hpp"

Scene2::Scene2() :
player(200, 200)
{}

void Scene2::initiateEntities() {
    this->initiateEntity(player);
}

void Scene2::updateEntities() {
    this->updateEntity(player);
}
