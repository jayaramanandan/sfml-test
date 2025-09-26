#ifndef SCENE_TPP
#define SCENE_TPP

#include "Scene.hpp"

#include <type_traits>
#include "Modules/Animator/Animator.hpp"
#include "Sprite/Sprite.hpp"
#include "GameManager/GameManager.hpp"

namespace builder {
    template<typename T>
    void Scene::initiateEntity(T& entity) {
        static_assert(std::is_base_of_v<SpriteEntity, T> || std::is_base_of_v<ShapeEntity, T>, "Unable to initiate an entity that is neither a sprite nor UI element");

        if constexpr (std::is_base_of_v<Sprite, T>) {
            if (entity.getTexturePath().data()) {
                entity.getDrawable().setTexture(
                    GameManager::getSpriteTexture(entity.getTexturePath())
                );
            }
        }

        entity.init();

        if constexpr (std::is_base_of_v<Animator, T>) {
            entity.startAnimationClocks();
        }
    }

    template<typename T>
    void Scene::pollEntityEvents(T& entity, sf::Event& event) {
        static_assert(std::is_base_of_v<SpriteEntity, T> || std::is_base_of_v<ShapeEntity, T>, "Unable to event poll an entity that is neither a sprite nor UI element");

        entity.pollEvent(event);
    }

    template<typename T>
    void Scene::updateEntity(T& entity) {
        static_assert(std::is_base_of_v<SpriteEntity, T> || std::is_base_of_v<ShapeEntity, T>, "Unable to update an entity that is neither a sprite nor UI element");

        entity.update();

        const sf::FloatRect bounds = entity.getDrawable().getGlobalBounds();
        sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
        myRect.setFillColor(sf::Color::Red);
        myRect.setPosition(bounds.getPosition());
        GameManager::getWindow()->draw(myRect);

        GameManager::getWindow()->draw(entity.getDrawable());
    }
}

#endif
