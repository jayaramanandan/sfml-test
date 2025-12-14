#include "Scene1.hpp"

Scene1::Scene1() :
player1(200, 200),
player2(200, 300)
{}

void Scene1::initiateEntities() {
    this->initiateEntity(player1);
    this->initiateEntity(player2);

    this->initiateEntity(button);
}

void Scene1::renderEntityEvents(sf::Event& event) {
    this->pollEntityEvents(player1, event);
    this->pollEntityEvents(player2, event);

    this->pollEntityEvents(button, event);
}

void Scene1::updateEntities() {
    this->updateEntity(player1);
    this->updateEntity(player2);

    this->updateEntity(button);
}
