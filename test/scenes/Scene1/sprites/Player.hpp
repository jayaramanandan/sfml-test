#ifndef PLAYER_H
#define PLAYER_H

#include "aliases.hpp"
#include "Entities/Sprite/Sprite.hpp"
#include "Entities/Animator/Animator.hpp"
#include "Entities/Motion/Motion.hpp"
#include "Entities/Collision/Collision.hpp"
#include "Entities/Listener/Listener.hpp"
#include "Entities/Listener/listeners/ClickListener.hpp"

class Player : public builder::Sprite, public builder::Animator, public builder::SpriteMotion, public builder::SpriteCollision, public builder::Listener<builder::ClickListener> {
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