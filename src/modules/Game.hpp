#include <unordered_map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"

#ifndef GAME_H
#define GAME_H

namespace maker {
    class Game {
        private:
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;
            std::vector<std::unique_ptr<maker::Sprite>> sprites;

        public:
            void addSprite(std::unique_ptr<maker::Sprite> sprite_ptr);
            void addSpriteTexture(const std::unique_ptr<maker::Sprite>& sprite_ptr);
            void run(const std::string& windowTitle, const int& width, const int& height);
    };
}

#endif