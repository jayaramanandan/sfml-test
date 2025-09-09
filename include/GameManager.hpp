#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <memory>
#include <string>
#include "SFML/Graphics.hpp"
#include "aliases.hpp"
#include "utility/Dictionary.hpp"
#include "utility/WindowDetails.hpp"

namespace builder {
    class GameManager {
    private:
        static WindowPtr window;
        static ScenesArray scenes;
        static int currentSceneIndex;
        static WindowDetails windowDetails;
        static Dictionary<sf::Texture> textures;
        static bool breakLoop;

    public:
        GameManager() = delete; // stops class being initiated (static class)

        static WindowPtr& getWindow();
        static void createWindow(const WindowDetails& details);

        static ScenePtr& getCurrentScene();
        static void setCurrentScene(const int& currentSceneIndexValue);

        template<class T, typename... Args>
        static void addScene(Args&&... args);

        static WindowDetails& getWindowDetails();
        static void setFrameRateDetails(const int& actualFrameRate, const int& observedFrameRate);

        static void setSpriteTextures(const std::string& directoryPath);
        static sf::Texture& getSpriteTexture(const std::string& texturePath);

        static void run();
    };
}

#include "GameManager.tpp"

#endif
