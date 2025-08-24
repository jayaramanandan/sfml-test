#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "utility/FrameRateDetails.hpp"
#include "Sprite.hpp"

namespace builder {
    template <class T>
    using Entity = std::shared_ptr<T>;

    class Game {
        private:
            FrameRateDetails frameRateDetails{};
            sf::RenderWindow window;
            std::unordered_map<std::string, sf::Texture> textures;

        public:
            Game(const std::string& windowTitle, const int& width, const int& height, const int& observedFrameRate, const int& actualFrameRate);
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