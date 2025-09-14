#include "../include/GameManager/GameManager.hpp"
#include "../test/scenes/Scene1/Scene1.hpp"
#include "../test/scenes/Scene2/Scene2.hpp"
#include "utility/WindowDetails.hpp"

int main() {
    builder::WindowDetails windowDetails;

    windowDetails.windowTitle = "Bowl Catcher";
    windowDetails.width = 800;
    windowDetails.height = 800;
    windowDetails.actualFrameRate = 60;
    windowDetails.observedFrameRate = 60;

    builder::GameManager::createWindow(windowDetails);

    builder::GameManager::setSpriteTextures("assets");

    builder::GameManager::addScene<Scene1>();
    builder::GameManager::addScene<Scene2>();

    builder::GameManager::run();

    return 0;
}