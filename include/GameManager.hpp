#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <memory>
#include "SFML/Graphics.hpp"
#include "aliases.hpp"
#include "utility/FrameRateDetails.hpp"
#include "utility/Dictionary.hpp"
#include "utility/WindowDetails.hpp"

namespace builder {
    class GameManager {
    private:
        static WindowPtr window;
        static ScenePtr currentScene;
        static FrameRateDetails frameRateDetails;
        static Dictionary<sf::Texture> textures;
        static bool breakLoop;

    public:
        GameManager() = delete; // stops class being initiated (static class)

        static WindowPtr& getWindow();
        static void createWindow(const WindowDetails& windowDetails);

        static ScenePtr& getCurrentScene();
        template<class T, typename... Args>
        static void setCurrentScene(Args&&... args);

        static FrameRateDetails& getFrameRateDetails();
        static void setFrameRateDetails(const FrameRateDetails& frameRateDetailsValue);

        static void addSpriteTexture(const SpritePtr& sprite_ptr);

        // move these to Scene class
        //void initiateEntity(const SpritePtr& sprite);
        //void pollEntityEvents(const Events& event, const SpritePtr& sprite);
        //void renderEntity(const SpritePtr& sprite);

        static void run();
    };
}

#include "GameManager.tpp"

#endif
