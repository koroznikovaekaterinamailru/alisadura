#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "component.h"
#include <typeinfo>
#include "gr_manager.h"
#include "script_manager.h"
#include "physics_manager.h"

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

            if (typeid(T).name() == typeid(Renderer).name())
            {
                GraphicsManager* GrManager = GraphicsManager::getInstance();
                GrManager -> addObject(obj);
            }
            else if (std::is_base_of<Script, T>())
            {
                ScriptManager* ScrManager = ScriptManager::getInstance();
                ScrManager -> addScript(obj);
            }
            else if (std::is_base_of<Collider, T>())
            {
                PhysicsManager* PhManager = PhysicsManager::getInstance();
                PhManager -> addCollider(obj);
            }

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
