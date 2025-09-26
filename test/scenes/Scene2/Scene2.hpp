#ifndef SCENE2_HPP
#define SCENE2_HPP

#include "Scene/Scene.hpp"
#include "../../sprites/Player.hpp"

class Scene2 : public builder::Scene {
    private:
        Player player;

    public:
        Scene2();

        void initiateEntities() override;
        void updateEntities() override;
};



#endif
