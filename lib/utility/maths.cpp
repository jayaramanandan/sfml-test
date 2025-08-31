#include <cmath>
#include "../../include/utility/maths.hpp"

float builder::toRad(const float& angle) {
        return angle * PI / 180;
}

builder::Components builder::getComponents(const float& magnitude, const float& degrees) {
    const float angleRad = toRad(degrees);

    Components components{};
    components.x = magnitude * std::sin(angleRad);
    components.y = magnitude * std::cos(angleRad);

    return components;
};