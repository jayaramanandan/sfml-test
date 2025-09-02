#include "../include/WindowManager.hpp"

namespace builder {
    sf::RenderWindow* WindowManager::window;

    sf::RenderWindow* WindowManager::getRenderWindow() {
        return window;
    }

    void WindowManager::setRenderWindow(sf::RenderWindow& windowValue) {
        window = &windowValue;
    }
}