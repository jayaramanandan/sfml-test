#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <memory>
#include <unordered_set>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Entities/Sprite.hpp"

namespace builder {
    class Scene;

    using SpritePtr = std::shared_ptr<Sprite>;
    using ShapePtr = std::shared_ptr<sf::Shape>;
    using ScenePtr = std::shared_ptr<Scene>; // circular definition
    using WindowPtr = std::shared_ptr<sf::RenderWindow>;

    using SpritesArray = std::unordered_set<SpritePtr>;
    using ShapesArray = std::unordered_set<ShapePtr>;
    using ScenesArray = std::vector<ScenePtr>;

    using Frames = const std::vector<std::array<int, 4>>;
    using ConsistentFrames = const std::vector<std::array<int, 2>>;

    using Event = sf::Event;
}

#endif
