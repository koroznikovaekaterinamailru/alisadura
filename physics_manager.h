#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H
#include "game_object.h"

class PhysicsManager
{
    public:
        static PhysicsManager* getInstance();
        void addCollider(GameObjectComponent* addingOfCollider);
        void removeCollider(GameObjectComponent* removingOfCollider);
        bool isCollision(Collider* object1 , Collider* object2);
        void allCollisions();

    private:
        static PhysicsManager* instance;
        std::vector <Collider*> collidingObjects;
};

#endif //PHYSICSMANAGER_H
