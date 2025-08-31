#include "../include/GameManager.hpp"
#include "Game.hpp"

namespace builder {
    Game* GameManager::game = nullptr;

    Game* GameManager::getGame() {
        return game;
    }

    void GameManager::setGame(Game *newGame) {
        game = newGame;
    }
}