#ifndef COMPONENT_H
#define COMPONENT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>



    class GameObject;

    class GameObjectComponent//создание класса компонент
    {
        public:
            GameObjectComponent();
            virtual ~GameObjectComponent() = 0;
            std::string name;
            GameObject* owner;
    };

    class Renderer : public GameObjectComponent //отрисовка
    {
        public:
            Renderer();
            void draw(sf::RenderWindow& window)
            {
                int x;
                int y;
                sprite.setPosition(x, y);
                window.draw(sprite);
            };
            void loadTexture(std::string texture_name)
            {
                texture.loadFromFile(texture_name);
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
            float width;//ширина прямоугольника,в котором сожержится объект
            float height;//высота прямоугольника,в котором сожержится объект
            float x;
            float y;
        private:
            std::vector<std::vector <float> > object_coordinate; //(координаты прямоугольника,в котором сожержится объект)
    };

    class Script : public GameObjectComponent
    {
        public:
            Script();
            virtual void update(float dt) {}
    };


#endif // COMPONENT_H
