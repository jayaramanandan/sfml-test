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
        static ScenesArray scenes;
        static int currentSceneIndex;
        static FrameRateDetails frameRateDetails;
        static Dictionary<sf::Texture> textures;
        static bool usingCache;
        static bool breakLoop;

    public:
        GameManager() = delete; // stops class being initiated (static class)

        static WindowPtr& getWindow();
        static void createWindow(const WindowDetails& windowDetails);

        static ScenePtr& getCurrentScene();
        static void setCurrentScene(const int& currentSceneIndexValue);

        template<class T, typename... Args>
        static void addScene(Args&&... args);

        static FrameRateDetails& getFrameRateDetails();
        static void setFrameRateDetails(const FrameRateDetails& frameRateDetailsValue);

        static void addSpriteTexture(const SpritePtr& sprite_ptr);

        static void useCache();

        static void run();
    };
}

#include "GameManager.tpp"

#endif
