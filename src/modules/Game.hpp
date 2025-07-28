#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

#ifndef GAME_H
#define GAME_H

namespace maker {
    class Game {
        private:
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;
            std::vector<maker::Sprite> sprites;

        public:
            void addSprite(maker::Sprite& sprite);
            void run(const std::string& windowTitle, const int& width, const int& height);
    };
}

#endif