#include <iostream>
#include <string>
#include "../include/utility/FrameRateDetails.hpp"
#include "../include/Sprite.hpp"
#include "../include/Animator.hpp"
#include "../include/Motion.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public builder::Sprite, public builder::Animator, public builder::Motion {
    public:
        Player(builder::FrameRateDetails* frameRateDetails);

        sf::Sprite* getSfSprite() override;
        
        void init() override;
        void update() override;
};

#endif