#include "../include/Scene.hpp"

builder::SpritesArray& builder::Scene::getSprites() {
    return  this->sprites;
}

builder::ShapesArray& builder::Scene::getShapes() {
    return this->uiElements;
}
