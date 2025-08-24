#ifndef PLAYER_H
#define PLAYER_H

#include "memory"
#include "Game.hpp"
#include "../include/Sprite.hpp"
#include "../include/Animator.hpp"
#include "../include/Motion.hpp"

class Player final : public builder::Sprite, public builder::Animator, public builder::Motion {
    public:
        Player(const float& x, const float& y);

        sf::Sprite* getSfSprite() override;
        
        void init() override;
        void update() override;
};

#endif