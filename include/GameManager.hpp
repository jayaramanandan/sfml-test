#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

namespace builder {
    class Game;

    class GameManager {
        private:
            static Game* game;

        public:
            GameManager() = delete;

            static Game* getGame();

            static void setGame(Game* newGame);
    };
}

#endif
