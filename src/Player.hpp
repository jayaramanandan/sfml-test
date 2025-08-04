#include <iostream>
#include "modules/Sprite.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public maker::Sprite {
    public:
        Player();

        void init() override;
        void update() override;
};

#endif