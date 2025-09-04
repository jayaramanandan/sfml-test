#include "Scene2.hpp"
#include "../Scene1/sprites/Player.hpp"

Scene2::Scene2() {
    auto player1 = this->addEntity<Player>(200, 200);
}
