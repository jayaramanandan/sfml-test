#include "Scene.hpp"

#include "GameManager.hpp"
#include "Entities/Animator.hpp"

namespace builder {
    SpritesArray& Scene::getSprites() {
        return this->sprites;
    }

    ShapesArray& Scene::getShapes() {
        return this->uiElements;
    }

    void Scene::initiateEntity(const SpritePtr& sprite_ptr) {
        if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

        sprite_ptr->getDrawable().setTexture(
            GameManager::getSpriteTexture(sprite_ptr->getTexturePath())
        );

        sprite_ptr->init();

        if (auto* sprite = dynamic_cast<Animator*>(sprite_ptr)) {
            sprite->startAnimationClocks();
        }
    }

    void Scene::renderEntity(const SpritePtr& sprite_ptr) {
        sprite_ptr->update();

        const sf::FloatRect bounds = sprite_ptr->getDrawable().getGlobalBounds();
        sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
        myRect.setFillColor(sf::Color::Red);
        myRect.setPosition(bounds.getPosition());
        GameManager::getWindow()->draw(myRect);

        GameManager::getWindow()->draw(sprite_ptr->getDrawable());
    }

    void Scene::initiateEntities() const {
        for (const auto& sprite_ptr : this->sprites) {
            initiateEntity(sprite_ptr);
        }

        /*
        for (const auto& shape_ptr : this->uiElements) {
            initiateEntity(shape_ptr);
        }*/
    }

    void Scene::renderEntities() const {
        for (const auto& sprite_ptr : this->sprites) {
            renderEntity(sprite_ptr);
        }

        /*
        for (const auto& shape_ptr : this->uiElements) {
            renderEntity(shape_ptr);
        }*/
    }
}
