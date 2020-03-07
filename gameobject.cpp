#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class GameObject
{
    public:      
        ~GameObject();//деструктор класса
        GameObject(std::string name);//конструктор класса (получаем на вход имя объекта)

        void setPosition(int x, int y); //эта функция устанавливает положение GameObject
   
       /* template <typename T>
        T* addComponent();//добавление новой компоненты для определённого GameObject */

        template <typename T>
        T* getComponent();//обращени к данной компоненте

       // std::vector<T*>; //все элементы будут одинакового размера
        
       // template <typename T>
        //bool hasComponent(); //проверка на наличие этого компонента в данном объекте
};

class GameObjectComponent//создание класса компонент
{
    public:
    GameObjectComponent();
    //virtual ~Component();
    std::string name = "";
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
        ~Renderer();
        //добавить параметры этого объекта ()
};

class Collider : public GameObjectComponent //взаимодействие между объектами
{
    public:
        Collider();
        ~Collider();
        //добавить параметры этого объекта ()
};

/*
template <typename T>
void GameObject::addComponent()
{
    //здесь будет функция которая добавляет компоненты к объектам
}*/

template <typename T>
T* GameObject::getComponent()
{ 
    for (component* c: components)
    {
        if (c -> name == name)
        {
            return static.cast<T*>(c);
        }
        return nullptr;
    }
};
/*
template <typename T>
bool GameObject::hasComponent()
{
    //проверка наличия этой компоненты у объекта
}*/
