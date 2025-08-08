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
            FrameRateDetails frameRateDetails{};
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;
            std::vector<std::unique_ptr<Sprite>> sprites;

        public:
            Game(const int& observedFrameRate, const int& actualFrameRate);
            FrameRateDetails* getFrameRateDetails();

            //void addSprite(std::unique_ptr<builder::Sprite> sprite_ptr);

            template <class T, typename... Args>
            void addSprite(Args&&... args);

            void addSpriteTexture(const std::unique_ptr<Sprite>& sprite_ptr);
            void run(const std::string& windowTitle, const int& width, const int& height);
    };

}

#include "Game.tpp"

#endif