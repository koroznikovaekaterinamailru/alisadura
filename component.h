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
        void draw(sf::RenderWindow& window);
        void loadTexture(std::string texture_name);
        void createSprite();
        sf::Sprite* getSprite();

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

class Collider : public GameObjectComponent //взаимодействие между объектами
{
    public:
        Collider();
        ~Collider();
        //добавить параметры этого объекта ()
};

class Script : public GameObjectComponent
{
    public:
        Script();
        virtual void update(float dt) {}
};

#endif // COMPONENT_H
