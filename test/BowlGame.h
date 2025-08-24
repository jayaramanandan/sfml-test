#ifndef BOWLGAME_H
#define BOWLGAME_H

#include "Game.hpp"
#include "Player.hpp"

class BowlGame final : public builder::Game{
    private:
        Player player;

    public:
        BowlGame();

        void initiateSprites() override;
        void render() override;
};



#endif