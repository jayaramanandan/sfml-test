#ifndef PLAYER_H
#define PLAYER_H

#include "aliases.hpp"
#include "Entities/Sprite.hpp"
#include "Entities/Animator.hpp"
#include "Entities/Motion.hpp"
#include "Entities/Collision.hpp"

class Player : public builder::Sprite, public builder::Animator, public builder::SpriteMotion, public builder::SpriteCollision {
    private:
        builder::SpritePtr player2{};
        bool moving = false;

    public:
        Player(float x, float y);
        Player(float x, float y, Player& player2);

        sf::Sprite& getDrawable() override;

        void init() override;
        void update() override;
};

#endif