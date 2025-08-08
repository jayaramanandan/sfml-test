#include <cmath>
#include "SFML/Graphics.hpp"

#ifndef MATHS_H
#define MATHS_H

namespace builder {
    const float PI = 3.141592;

    struct Components {
        float x;
        float y;
    };

    float toRad(const float& angle);
    Components getComponents(const float& magnitude, const float& degrees);
}

#endif