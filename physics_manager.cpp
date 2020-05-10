#include "physics_manager.h"

PhysicsManager* PhysicsManager::getInstance(){

    if(!instance){
        instance = new PhysicsManager;
    }
    return instance;
}
PhysicsManager* PhysicsManager::instance = NULL;

void PhysicsManager::addCollider(GameObjectComponent* addingOfCollider)
{
    collidingObjects.push_back(static_cast <Collider*> (addingOfCollider));
}

void PhysicsManager::removeCollider(GameObjectComponent* removingOfCollider)
{
    for(int i = 0 ; i < collidingObjects.size() ; i++)
    {
        if(collidingObjects[i] == removingOfCollider)
        {
            collidingObjects.erase(collidingObjects.begin() + i);
        }
    }
}

bool PhysicsManager::isCollision(Collider* object1 , Collider* object2)
{
    bool XColl=false;
    bool YColl=false;
    if(((*object1).x + (*object1).width == (*object2).x) || ((*object2).x + (*object2).width == (*object1).x))
        XColl = true;

    if (((*object1).y + (*object1).height == (*object2).y) || ((*object2).y + (*object2).height == (*object2).y))
    {
        YColl = true;
    }
    if (XColl&YColl)
    {
        std::cout << "collision" << std::endl;
        return true;
    }
    return false;
}

void PhysicsManager::allCollisions()
{
    for (int i = 0; i < collidingObjects.size(); i++)
    {
        for (int j = 0; j < collidingObjects.size(); j++)
        {
            if (i > j)
            {
                isCollision(collidingObjects[i], collidingObjects[j]);
            }
        }
    }
}
