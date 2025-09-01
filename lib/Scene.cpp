#include "../include/Scene.hpp"
#include "../include/Entities/Animator.hpp"
#include "../include/Entities/Motion.hpp"
#include "../include/Game.hpp"

std::vector<builder::SpriteCollision*> builder::Scene::getClickListenerSprites() const {
    return this->clickListenerSprites;
}

std::vector<builder::ShapeCollision*> builder::Scene::getClickListenerShapes() const {
    return this->clickListenerShapes;
}

void builder::Scene::initiateEntity(Sprite &sprite) const {
    this->game->addSpriteTexture(sprite);
    sprite.init();

    if (const auto* sprite_ptr = dynamic_cast<Animator*>(&sprite)) {
        sprite_ptr->startAnimationClocks();
    }
    if (auto* sprite_ptr = dynamic_cast<SpriteMotion*>(&sprite)) {
        sprite_ptr->setFrameRateDetails(this->game->getFrameRateDetails());
    }
}


void builder::Scene::renderEntity(Sprite& sprite) const {
    sprite.update();

    const sf::FloatRect bounds = sprite.getSfSprite()->getGlobalBounds();
    sf::RectangleShape myRect(sf::Vector2f(bounds.width, bounds.height));
    myRect.setFillColor(sf::Color::Red);
    myRect.setPosition(bounds.getPosition());
    this->game->getWindow()->draw(myRect);

    this->game->getWindow()->draw(*sprite.getSfSprite());
}

void builder::Scene::addClickListener(SpriteCollision* sprite) {
    this->clickListenerSprites.push_back(sprite);
}

void builder::Scene::addClickListener(ShapeCollision* shape) {
    this->clickListenerShapes.push_back(shape);
}