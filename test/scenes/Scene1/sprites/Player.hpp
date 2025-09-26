#ifndef PLAYER_H
#define PLAYER_H

#include "aliases.hpp"
#include "Entities/Modules.hpp"
#include "Entities/Sprite/Sprite.hpp"
#include "Entities/Animator/Animator.hpp"
#include "Entities/Motion/Motion.hpp"
#include "Entities/Collision/Collision.hpp"


class Player :
public builder::Modules<
    builder::Sprite,
    builder::Animator,
    builder::SpriteMotion,
    builder::SpriteCollision
>
{
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