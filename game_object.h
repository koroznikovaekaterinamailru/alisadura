#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "component.h"
#include <typeinfo>
#include "gr_manager.h"
#include "script_manager.h"

class GameObjectComponent;

class GameObject
{
    public:
        sf::Vector2f position;
        //std::string id_in_data_storage;  // it's not good
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
            else if (typeid(T).name() == typeid(Script).name())
            {
                ScriptManager* script_manager = ScriptManager::getInstance();
                script_manager -> addScript(obj);
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
