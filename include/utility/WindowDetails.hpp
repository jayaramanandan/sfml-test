#ifndef WINDOWDETAILS_H
#define WINDOWDETAILS_H

#include <string>
#include "FrameRateDetails.hpp"

namespace builder {
    struct WindowDetails : public FrameRateDetails{
        std::string windowTitle;
        int width;
        int height;
    };
}

#endif
