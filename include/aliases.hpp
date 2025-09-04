#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <memory>
#include <unordered_set>
#include "SFML/Graphics.hpp"
#include "Entities/Sprite.hpp"

namespace builder {
    class Scene;
    using SpritePtr = std::shared_ptr<Sprite>;
    using ShapePtr = std::shared_ptr<sf::Shape>;
    using SpritesArray = std::unordered_set<SpritePtr>;
    using ShapesArray = std::unordered_set<ShapePtr>;
    using ScenePtr = std::shared_ptr<Scene>; // circular definition
}

#endif
