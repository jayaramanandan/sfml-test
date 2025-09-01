#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "Game.hpp"
#include "Entities/Sprite.hpp"
#include "Entities/Collision.hpp"

namespace builder {
    class Scene {
        private:
            Game* game;
            int sceneId = 0;
            std::vector<SpriteCollision*> clickListenerSprites{};
            std::vector<ShapeCollision*> clickListenerShapes{};

        public:
            virtual ~Scene() = default;

            sf::RenderWindow* getWindow();

            [[nodiscard]] std::vector<SpriteCollision*> getClickListenerSprites() const;
            [[nodiscard]] std::vector<ShapeCollision*> getClickListenerShapes() const;

            void initiateEntity(Sprite& sprite) const;
            void pollEntityEvent(Sprite& event) const;
            void renderEntity(Sprite& sprite) const;

            void addClickListener(SpriteCollision* sprite);
            void addClickListener(ShapeCollision* shape);

            virtual void initiateSprites() = 0;
            virtual void render() = 0;
    };
}

#endif
