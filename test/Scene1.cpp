#include "Scene1.hpp"

Scene1::Scene1() :
player(200, 200, &player2),
player2(200, 340) {}


void Scene1::initiateSprites() {
    initiateSprite(player);
    initiateSprite(player2);
}

void Scene1::render() {
    renderSprite(player);
    renderSprite(player2);
}
