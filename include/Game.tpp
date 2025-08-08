#ifndef GAME_T
#define GAME_T

#include "Game.hpp"
namespace builder {
    template <typename T, typename... Args>
    void Game::addSprite(Args&&... args) {
        //auto sprite_ptr = ;
        this->sprites.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
}


#endif