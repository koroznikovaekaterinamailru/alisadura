#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H
#include <vector>
#include "game_object.h"
#include <iostream>

class PhysicsManager
{
    public:
        void addCollider(GameObjectComponent* add_collider);
        void removeCollider(GameObjectComponent* remove_collider);
        void collision_of_two(Collider* object_1 , Collider* object_2);
        void all_collisions();

    private:
        PhysicsManager() {}
        std::vector <Collider*> colliding_obj;
};

void PhysicsManager::addCollider(GameObjectComponent* add_collider)
{
    colliding_obj.push_back(static_cast <Collider*> (add_collider));
}

void PhysicsManager::removeCollider(GameObjectComponent* remove_collider)
{
    for(int i = 0 ; i < colliding_obj.size() ; i++)
    {
        if(colliding_obj[i] == remove_collider)
        {
            colliding_obj.erase(colliding_obj.begin() + i);
        }
    }
}

void PhysicsManager::collision_of_two(Collider* object_1 , Collider* object_2)
{   

}

void PhysicsManager::all_collisions()
{
    for (int i = 0; i < colliding_obj.size(); i++)
    {
        for (int j = 0; j < colliding_obj.size(); j++)
        {
            if (i > j)
            {
                collision_of_two(colliding_obj[i], colliding_obj[j]);
            }
        }
    }
}

#endif //PHYSICSMANAGER_H
