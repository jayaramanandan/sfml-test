#ifndef COLLISION_TPP
#define COLLISION_TPP

#include "Collision.hpp"

namespace builder {
    template<ValidType T>
    bool Collision<T>::checkClicks() {
        return false;
    }

    template<ValidType T>
    bool Collision<T>::isColliding(const SpritePtr& sprite_ptr) {
        return this->getDrawable().getGlobalBounds().intersects(
            sprite_ptr->getDrawable().getGlobalBounds()
        );
    }
}

#endif