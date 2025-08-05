#ifndef MOTION_H
#define MOTION_H

namespace builder {
    struct FrameRateDetails {
        int observedFrameRate;
        int actualFrameRate;
    };

    class Motion {
        private:
            FrameRateDetails frameRateDetails;
    };
}

#endif