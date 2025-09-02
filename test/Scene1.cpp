#include "Scene1.hpp"
#include "Player.hpp"

Scene1::Scene1() {
    auto player1 = this->addEntity<Player>(200, 200);
    auto player2 = this->addEntity<Player>(200, 300, player1);
}