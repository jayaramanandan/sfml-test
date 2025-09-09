#ifndef MATHS_H
#define MATHS_H

#include <cmath>

namespace builder {
    constexpr float PI = 3.14159265358979323846f;

    struct Components {
        float x;
        float y;
    };

    constexpr float toRad(const float angle) {
        return angle * PI / 180.0f;
    }

    constexpr Components getComponents(const float magnitude, const float degrees) {
        const float angleRad = toRad(degrees);
        return { magnitude * std::cos(angleRad), magnitude * std::sin(angleRad) };
    }
}

#endif