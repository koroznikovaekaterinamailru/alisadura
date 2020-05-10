ifndef COMPONENT_H
#define COMPONENT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <typeinfo>

    class GameObject;

    class GameObjectComponent//создание класса компонент
    {
        public:
            std::string name;
            GameObject* owner;
    };

    class Renderer : public GameObjectComponent //отрисовка
    {
        public:
            Renderer()
            {
                name = typeid(*this).name();
            };
            void draw(sf::RenderWindow& window);
            void loadTexture(std::string textureName)
            {
                texture.loadFromFile(textureName);
            };
            void createSprite()
            {
                sprite.setTexture(texture);
            };
            sf::Sprite* getSprite()
            {
                return &sprite;
            };

        private:
            sf::Texture texture;
            sf::Sprite sprite;
    };

    class Collider: public GameObjectComponent
    {
        public:
            Collider();
            bool isCollision();
            float width;//ширина прямоугольника,в котором содержится объект
            float height;//высота прямоугольника,в котором содержится объект
            float x;
            float y;
        private:
            std::vector<std::vector <float> > object_coordinate; //(координаты прямоугольника,в котором содержится объект)
    };

    class Script : public GameObjectComponent
    {
        public:
            Script();
            virtual void update(float dt) {}
    };

#endif // COMPONENT_H

