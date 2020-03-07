#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class GameObject
    {
    public:
       
        ~GameObject();//деструктор класса
        GameObject(std::string name);//конструктор класса (получаем на вход имя объекта)

        void setPosition(int x, int y); //эта функция устанавливает положение GameObject

        template <typename ComponentType>//это шаблон
	    class GameObjectComponent //создание класса компонент
	    {
	    public:
	        GameObjectComponent();
	        std::string name = "";

	    };

	    template <typename ComponentType>
        void addComponent(); //добавление новой компоненты для определённого GameObject

        template <typename ComponentType>
        ComponentType* getComponent();//обращение к данной компоненте

        template <typename ComponentType>
        bool hasComponent(); //проверка на наличие этого компонента в данном объекте

        //далее все функции регистрируют/удаляют компоненты из объектов???????
        void registerObjectScript(GameObjectComponent* script);
        void unregisterObjectScript(GameObjectComponent* script);

        void registerObjectRenderer(GameObjectComponent* renderer);
        void unregisterObjectRenderer(GameObjectComponent* renderer);

        void registerObjectCollider(GameObjectComponent* collider);
        void unregisterObjectCollider(GameObjectComponent* collider);

        void registerObjectPhysicalBody(GameObjectComponent* physBody);
        void unregisterObjectPhysicalBody(GameObjectComponent* physBody);
    };


    class PhysicalBody : public GameObjectComponent
    {
    public:
        PhysicalBody();
        ~PhysicalBody();
        //добавить параметры этого объекта ()
        float mass = ;
	};



	class Renderer : public GameObjectComponent
    {
    public:
    	Renderer();
    	~Renderer();
    	//добавить параметры этого объекта ()
    };

    class Collider : public GameObjectComponent
    {
    public:
    	Collider();
    	~Collider();
    	//добавить параметры этого объекта ()
    }

    class Script //че-то пока непонятно что с этим делать




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
