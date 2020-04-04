#ifndef SINGLETON_H
#define SINGLETON_H
#include <SFML/Graphics.hpp>
#include "data_storage.h"
#include "game_object.h"
#include "gr_manager.h"
#include "script_manager.h"
#include "physics_manager.h"

class Singleton
{
    public:
        static Singleton* getInstance();
        DataStorage datastorage;
        GraphicsManager graphicsmanager;
        PhysicsManager physicsmanager;
        //ScriptManager scriptmanager;
        float dt;
    private:
        static Singleton* instance;
};

Singleton* Singleton::getInstance()
{
    if (!instance)
        instance = new Singleton();
    return instance;
}

Singleton* Singleton::instance = NULL;

#endif //SINGLETON_H
