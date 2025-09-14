#ifndef SCENE2_HPP
#define SCENE2_HPP

#include "../../../include/Scene/Scene.hpp"
#include "../Scene1/sprites/Player.hpp"

class Scene2 : public builder::Scene {
    private:
        Player player;

    public:
        Scene2();
};



#endif
