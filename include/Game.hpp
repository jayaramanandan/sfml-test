#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include "utility/FrameRateDetails.hpp"
#include "Entities/Sprite.hpp"
#include "utility/WindowDetails.hpp"
#include "utility/Dictionary.hpp"

namespace builder {
    class Scene; // Forward declaration instead of including Scene.hpp

    using Events = sf::Event;

    class Game {
        private:
            sf::RenderWindow window;
            FrameRateDetails frameRateDetails;
            std::string currentSceneName;
            Dictionary<Scene*> scenes;
            Dictionary<sf::Texture> textures;

        public:
            Game(const WindowDetails& windowDetails, const FrameRateDetails& frameRateDetails);
            virtual ~Game() = default;

            FrameRateDetails* getFrameRateDetails();
            sf::RenderWindow* getWindow();
            Scene* getCurrentScene() const;

            void addSpriteTexture(Sprite& sprite);
            void addScene(const std::string& sceneName, Scene* scene);
            void run();
    };
}

#endif