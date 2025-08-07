#include <iostream>
#include <string>
#include "modules/utility/FrameRateDetails/FrameRateDetails.hpp"
#include "modules/Sprite/Sprite.hpp"
#include "modules/Animator/Animator.hpp"
#include "modules/Motion/Motion.hpp"

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