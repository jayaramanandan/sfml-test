#include "../test/BowlGame.hpp"
#include "../include/utility/WindowDetails.hpp"
#include "../include/utility/FrameRateDetails.hpp"

int main() {
    builder::WindowDetails windowDetails;
    builder::FrameRateDetails frameRateDetails{};

    windowDetails.windowTitle = "Bowl Catcher";
    windowDetails.width = 800;
    windowDetails.height = 800;
    frameRateDetails.observedFrameRate = 30;
    frameRateDetails.actualFrameRate = 60;

    BowlGame game(windowDetails, frameRateDetails);

    return 0;
}