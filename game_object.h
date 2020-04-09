#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "component.h"
#include "gr_manager.h"
#include "script_manager.h"
#include "physics_manager.h"
#include "singleton.h"

class GameObject
{
    public:      

        void setPosition(int x, int y);
        template <typename T>
        bool addComponent()//добавление новой компоненты для определённого GameObject 
        {
            T* obj = new T;
            components.push_back(obj);
            components[components.size() - 1]->owner = this;
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
        
        template <typename T>
        bool removeComponent()
        {
            for (int i = 0; i < components.size(); i++)
            {
                if (components[i]->name == name)
                {
                    delete components[i];
                    components.erase(components.begin() + i);
                    return true;
                }
                return false;
            }
        }
    
    private:
        std::vector<GameObjectComponent*> components; 
        std::string name;
};

#endif // GAMEOBJECT_H
