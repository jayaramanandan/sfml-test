#ifndef BOWLGAME_H
#define BOWLGAME_H

#include "Game.hpp"
#include "Player.hpp"
#include "../include/utility/WindowDetails.hpp"
#include "../include/utility/FrameRateDetails.hpp"

class BowlGame final : public builder::Game{
    private:
        Player player;

    public:
        BowlGame(builder::WindowDetails& windowDetails, builder::FrameRateDetails& frameRateDetails);

        void initiateSprites() override;
        void render() override;
};



#endif