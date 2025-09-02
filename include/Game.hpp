#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include "utility/FrameRateDetails.hpp"
#include "utility/WindowDetails.hpp"
#include "utility/Dictionary.hpp"
#include "aliases.hpp"

namespace builder {
    class Scene; // Forward declaration instead of including Scene.hpp

    using Events = sf::Event;

    class Game {
        private:
            sf::RenderWindow window;
            FrameRateDetails frameRateDetails{};
            std::string currentSceneName;
            Dictionary<Scene*> scenes;
            Dictionary<sf::Texture> textures;

        public:
            Game(const WindowDetails& windowDetails, const FrameRateDetails& frameRateDetails);
            virtual ~Game() = default;

            FrameRateDetails* getFrameRateDetails();
            sf::RenderWindow* getWindow();
            Scene* getCurrentScene() const;

            void addSpriteTexture(const SpritePtr& sprite_ptr);

            void initiateEntity(const SpritePtr& sprite);
            static void pollEntityEvents(const Events& event, const SpritePtr& sprite);
            void renderEntity(const SpritePtr& sprite);

            void addScene(const std::string& sceneName, Scene* scene);
            void setCurrentScene(const std::string& sceneName);

            void run();
    };
}

#endif