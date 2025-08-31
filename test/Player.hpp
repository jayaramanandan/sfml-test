#ifndef PLAYER_H
#define PLAYER_H

#include "../include/Entities/Sprite.hpp"
#include "../include/Entities/Animator.hpp"
#include "../include/Entities/Motion.hpp"
#include "../include/Entities/Collision.hpp"

class Player final : public builder::Sprite, public builder::Animator, public builder::Motion<sf::Sprite>, public builder::Collision<sf::Sprite> {
    private:
        Player* player2{};

    public:
        Player(const float& x, const float& y);
        Player(const float& x, const float& y, Player* player2);

        sf::Sprite* getDrawable() override;

        void init() override;
        void update() override;
};

#endif