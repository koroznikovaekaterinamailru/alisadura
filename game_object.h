#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "component.h"
#include "gr_manager.h"
#include "script_manager.h"
#include "physics_manager.h"
#include <typeinfo>

class GraphicsManager;
class PhysicsManager;

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
            /*GraphicsManager* GrManager = GraphicsManager::getInstance();
            if(typeid(T).name() == typeid(Renderer).name())
            {
                GrManager->addObject(obj);
            }
            else if(typeid(T).name() == typeid(Script).name())
            {
                ScriptManager* ScriptManager = ScriptManager::getInstance();
                ScriptManager -> addScript(obj);
            }
            else if(typeid(T).name() == typeid(Collider).name())
            {
                PhysicsManager* PhManager = PhysicsManager::getInstance();
                PhManager -> addCollider(obj);
            }*/
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
        bool removeComponent()
        {
            std::string name = typeid(T).name();
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
};

#endif // GAMEOBJECT_H
