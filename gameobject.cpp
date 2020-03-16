#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class GameObjectComponent//создание класса компонент
{
    public:
    GameObjectComponent();
    std::string name;
};

class GameObject: public GameObjectComponent
{
    public:      
        ~GameObject();//деструктор класса
        GameObject();//конструктор класса (получаем на вход имя объекта)

        void setPosition(int x, int y); //эта функция устанавливает положение GameObject
        std::vector<GameObjectComponent*> components; //все элементы будут одинакового размера



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

int main()
{
    
    std::cout << '6'; 
    return 0;
}
