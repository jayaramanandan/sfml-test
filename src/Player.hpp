#include <iostream>
#include <string>
#include "modules/Sprite.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public builder::Sprite {
    public:
        void init() override;
        void update() override;
};

#endif