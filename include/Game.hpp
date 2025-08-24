#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "utility/FrameRateDetails.hpp"
#include "Sprite.hpp"
#include "utility/WindowDetails.hpp"

namespace builder {
    class Game {
        private:
            FrameRateDetails frameRateDetails{};
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;

        public:
            Game(WindowDetails& windowDetails, FrameRateDetails& frameRateDetails);
            virtual ~Game() = default;

            FrameRateDetails* getFrameRateDetails();

            void initiateSprite(Sprite& sprite);
            void renderSprite(Sprite& sprite);

            void addSpriteTexture(Sprite& sprite);

            virtual void initiateSprites() = 0;
            virtual void render() = 0;
            void run();
    };

}

#endif