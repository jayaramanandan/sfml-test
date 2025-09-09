#ifndef SCENE1_HPP
#define SCENE1_HPP

#include "Scene.hpp"
#include "sprites/Player.hpp"

class Scene1 : public builder::Scene {
    private:
        Player player1;
        Player player2;

    public:
        Scene1();
};

#endif
