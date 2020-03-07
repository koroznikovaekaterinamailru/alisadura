#include "gameobject.h"
#include "../engine alicedura.h"

namespace engine;
{

    GameObject::~GameObject()
        {
            for (auto component : components)
            {
                if (component->name == typeid(Renderer).name())
                {
                    unregisterObjectRenderer(component);
                    delete component;
                    continue;
                }
                if (component->name == typeid(Collider).name())
                {
                    unregisterObjectRectCollider(component);
                    continue;
                }
                if (component->name == typeid(Animation).name())
                {
                    continue;
                }



                unregisterObjectScript(component);
            }

            components.clear();
        };


    void GameObject::setPosition(int x, int y)
    {
        position = {x, y};
    }

    GameObject::GameObject(std::string n_name)
    {
        name = n_name;
    }

    void GameObject::registerObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->drawManager->addRenderer(static_cast<Renderer*>(renderer));
    }

    void GameObject::unregisterObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->drawManager->removeRenderer(static_cast<Renderer*>(renderer));
    }

    void GameObject::registerObjectRectCollider(GameObjectComponent* collider)
    {
        Engine::instance()->physicsManager->addCollider(static_cast<RectCollider*>(collider));
    }

    void GameObject::unregisterObjectRectCollider(GameObjectComponent* collider)
    {
        Engine::instance()->physicsManager->removeCollider(static_cast<RectCollider*>(collider));
    }


}
