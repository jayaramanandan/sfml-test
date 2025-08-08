#ifndef PLAYER_H
#define PLAYER_H

#include "../include/Sprite.hpp"
#include "../include/Animator.hpp"
#include "../include/Motion.hpp"

class Player final : public builder::Sprite, public builder::Animator, public builder::Motion {
    public:
        Player();

        sf::Sprite* getSfSprite() override;
        
        void init() override;
        void update() override;
};

#endif