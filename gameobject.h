#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class GameObject
{
    public:      
        ~GameObject();//деструктор класса
        GameObject(std::string name);//конструктор класса (получаем на вход имя объекта)
        std::vector<Component*>; //все элементы будут одинакового размера

        void setPosition(int x, int y); //эта функция устанавливает положение GameObject

        template <typename ComponentType>//это шаблон
        class GameObjectComponent //создание класса компонент
        {
        public:
            GameObjectComponent();
            virtual ~Component();
            std::string name = "";
            class Body //материальные объекты
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
        };

        template <typename ComponentType>
        void addComponent(); //добавление новой компоненты для определённого GameObject

        template <typename ComponentType>
        ComponentType* getComponent();//обращение к данной компоненте

        template <typename ComponentType>
        bool hasComponent(); //проверка на наличие этого компонента в данном объекте
};

template <typename ComponentType>
void GameObject::addComponent()
{
    //здесь будет функция которая добавляет компоненты к объектам
}

template <typename ComponentType>
ComponentType* GameObject::getComponent()
{
   //обращение к данной компоненте
}

template <typename ComponentType>
bool GameObject::hasComponent()
{
    //проверка наличия этой компоненты у объекта
}
