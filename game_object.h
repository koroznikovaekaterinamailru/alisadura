#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "component.h"

class GameObjectComponent;

class GameObject
{
    public:
        sf::Vector2f position;
        void setPosition(float x, float y)
        {
            position = {x, y};
        }

        template <typename T>
        void addComponent()//добавление новой компоненты для определённого GameObject 
        {
            T* obj = new T;
            components.push_back(obj);
            components[components.size() - 1]->owner = this;
        }

        template <typename T>
        T* getComponent()//обращение к данной компоненте
        {
            std::string name = typeid(T).name();
            for (GameObjectComponent* c: components)
            {
                if (c->name == typeid(T).name())            
                {
                    return static_cast<T*>(c);                   
                }
                return NULL; 
            } 
        }; 
        
        template <typename T>
        void removeComponent()
        {
            std::string name = typeid(T).name();
            for (int i = 0; i < components.size(); i++)
            {
                if (components[i]->name == name)
                {
                    delete components[i];
                    components.erase(components.begin() + i);
                }
            }
        }
    
    private:
        std::vector<GameObjectComponent*> components; 
};

#endif // GAMEOBJECT_H
