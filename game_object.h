#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class GameObjectComponent//создание класса компонент
{
    public:
        GameObjectComponent();
        virtual ~GameObjectComponent() = 0;
        std::string name;
};

class GameObject: public GameObjectComponent
{
    public:      
        ~GameObject();//деструктор класса
        GameObject();//конструктор класса (получаем на вход имя объекта)


        template <typename T>
        T* addComponent()//добавление новой компоненты для определённого GameObject 
        {
            T* obj = new T;
            GameObjectComponent : append(obj);
        };

        template <typename T>
        T* getComponent()//обращение к данной компоненте
        {
            for (GameObjectComponent* c: components)
            {
                if (c -> name == name)            
                {
                    return static_cast<T*>(c);                   
                }
                return NULL; 
            } 
        }; 
        void registerObjectRenderer(GameObjectComponent* renderer);
        void unregisterObjectRenderer(GameObjectComponent* renderer);   

    private:
        std::vector<GameObjectComponent*>::iterator components; 
};

class Body : public GameObjectComponent //материальные объекты
{
    public:
        Body();
        ~Body();
        //добавить параметры этого объекта ()
        float mass;
        float velocity;
};

class Renderer : public GameObjectComponent //отрисовка
{
    public:
        Renderer();
        void draw(sf::RenderWindow& window);
        void loadTexture(std::string texture_name);

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

#endif // GAMEOBJECT_H
