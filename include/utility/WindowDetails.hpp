#ifndef WINDOWDETAILS_H
#define WINDOWDETAILS_H

#include <string>

namespace builder {
    struct WindowDetails {
        std::string windowTitle;
        int width;
        int height;
        int observedFrameRate = 60;
        int actualFrameRate = 60;
    };
}

#endif
