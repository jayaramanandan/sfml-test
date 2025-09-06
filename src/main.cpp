#include <iostream>
#include "GameManager.hpp"
#include "../test/scenes/Scene1/Scene1.hpp"
#include "utility/WindowDetails.hpp"

int main() {
    builder::WindowDetails windowDetails;

    windowDetails.windowTitle = "Bowl Catcher";
    windowDetails.width = 800;
    windowDetails.height = 800;
    windowDetails.actualFrameRate = 60;
    windowDetails.observedFrameRate = 30;

    builder::GameManager::createWindow(windowDetails);

    builder::GameManager::setCurrentScene<Scene1>();
    builder::GameManager::setFrameRateDetails(windowDetails);

    builder::GameManager::run();

    return 0;
}