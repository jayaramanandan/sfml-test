#ifndef SCENE1_HPP
#define SCENE1_HPP

#include "Scene/Scene.hpp"
#include "../../sprites/Player.hpp"
#include "../../sprites/StartButton.hpp"

class Scene1 : public builder::Scene {
    private:
        Player player1;
        Player player2;
        StartButton button;

    public:
        Scene1();

        void initiateEntities() override;
        void renderEntityEvents(sf::Event& event) override;
        void updateEntities() override;
};

#endif
