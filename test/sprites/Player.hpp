#ifndef PLAYER_H
#define PLAYER_H

#include "aliases.hpp"
#include "Modules/Modules.hpp"
#include "Sprite/Sprite.hpp"
#include "Modules/Animator/Animator.hpp"
#include "Modules/Motion/Motion.hpp"
#include "Modules/Collision/Collision.hpp"


class Player :
public builder::Modules<
    builder::Sprite,
    builder::Animator,
    builder::SpriteMotion,
    builder::SpriteCollision
>
{
    private:
        builder::SpritePtr player2 = nullptr;
        bool moving = false;

    public:
        Player(float x, float y);
        Player(float x, float y, builder::SpritePtr player2);

        sf::Sprite& getDrawable() override;

        void init() override;
        void update() override;
};

#endif