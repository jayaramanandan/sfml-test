#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include "aliases.hpp"
#include "SFML/Graphics.hpp"

namespace builder {
    class GameManager {
    private:
        static sf::RenderWindow* window;
        static ScenePtr currentScene;

    public:
        static sf::RenderWindow* getRenderWindow();
        static void setRenderWindow(sf::RenderWindow& windowValue);

        static ScenePtr& getCurrentScene();
        template <class T>
        static void setCurrentScene();
    };
}

#include "GameManager.tpp"

#endif
