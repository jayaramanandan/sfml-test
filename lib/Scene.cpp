#include "Scene.hpp"
#include "GameManager.hpp"
#include "Entities/Animator.hpp"

builder::SpritesArray& builder::Scene::getSprites() {
    return  this->sprites;
}

builder::ShapesArray& builder::Scene::getShapes() {
    return this->uiElements;
}

void builder::Scene::initiateEntity(const SpritePtr& sprite_ptr) {
    if (!sprite_ptr) throw std::invalid_argument("Sprite pointer is null");

    GameManager::addSpriteTexture(sprite_ptr); // continue here
    sprite_ptr->init();

    if (const auto* sprite = dynamic_cast<Animator*>(sprite_ptr.get())) {
        sprite->startAnimationClocks();
    }
}

void builder::Scene::renderEntity(const SpritePtr& sprite_ptr) {
    sprite_ptr->update();

    const sf::FloatRect bounds = sprite_ptr->getDrawable().getGlobalBounds();
    sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
    myRect.setFillColor(sf::Color::Red);
    myRect.setPosition(bounds.getPosition());
    GameManager::getWindow()->draw(myRect);

    GameManager::getWindow()->draw(sprite_ptr->getDrawable());
}

void builder::Scene::initiateEntities() const {
    for (const auto& sprite_ptr : this->sprites) {
        initiateEntity(sprite_ptr);
    }

    /*
    for (const auto& shape_ptr : this->uiElements) {
        initiateEntity(shape_ptr);
    }*/
}

void builder::Scene::renderEntities() const {
    for (const auto& sprite_ptr : this->sprites) {
        renderEntity(sprite_ptr);
    }
}
