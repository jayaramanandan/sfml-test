#ifndef SCENE1_HPP
#define SCENE1_HPP

#include "../include/Scene.hpp"
#include "Player.hpp"

class Scene1 : public builder::Scene {
    private:
        Player player;
        Player player2;
    public:
        Scene1();
        void initiateSprites() override;
        void render() override;
};

#endif
