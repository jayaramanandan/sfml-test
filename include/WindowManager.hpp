#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include "SFML/Graphics.hpp"

namespace builder {
    class WindowManager {
    private:
        static sf::RenderWindow* window;

    public:
        static sf::RenderWindow* getRenderWindow();
        static void setRenderWindow(sf::RenderWindow& windowValue);
    };
}

#endif
