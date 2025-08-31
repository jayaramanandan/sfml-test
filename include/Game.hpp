#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Entities/Collision.hpp"
#include "utility/FrameRateDetails.hpp"
#include "Entities/Sprite.hpp"
#include "utility/WindowDetails.hpp"
#include "utility/Dictionary.hpp"

namespace builder {
    class Game {
        private:
            FrameRateDetails frameRateDetails{};
            sf::RenderWindow window;
            Dictionary<sf::Texture> textures;
            std::vector<SpriteCollision*> clickListenerSprites{};
            std::vector<ShapeCollision*> clickListenerShapes{};

        public:
            Game(const WindowDetails& windowDetails, const FrameRateDetails& frameRateDetails);
            virtual ~Game() = default;

            FrameRateDetails* getFrameRateDetails();
            sf::RenderWindow* getWindow();

            void initiateSprite(Sprite& sprite);
            void renderSprite(Sprite& sprite);

            void addSpriteTexture(Sprite& sprite);

            void addClickListener(SpriteCollision* sprite);
            void addClickListener(ShapeCollision* shape);

            virtual void initiateSprites() = 0;
            virtual void render() = 0;
            void run();
    };

}

#endif