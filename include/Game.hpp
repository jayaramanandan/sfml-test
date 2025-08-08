#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "utility/FrameRateDetails.hpp"
#include "Sprite.hpp"

namespace builder {
    class Game {
        private:
            builder::FrameRateDetails frameRateDetails;
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;
            std::vector<std::unique_ptr<builder::Sprite>> sprites;

        public:
            Game(const int& observedFrameRate, const int& actualFrameRate);
            builder::FrameRateDetails* getFrameRateDetails();
            void addSprite(std::unique_ptr<builder::Sprite> sprite_ptr);
            void addSpriteTexture(const std::unique_ptr<builder::Sprite>& sprite_ptr);
            void run(const std::string& windowTitle, const int& width, const int& height);
    };
}

#endif