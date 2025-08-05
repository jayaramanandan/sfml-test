#include <iostream>
#include <string>
#include "modules/Sprite.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public builder::Sprite, public builder::Animator {
    public:
        Player();

        sf::Sprite* getSfSprite() override;
        
        void update() override;
};

#endif