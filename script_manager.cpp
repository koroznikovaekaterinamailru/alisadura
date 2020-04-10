#include "script_manager.h"

ScriptManager* ScriptManager::getInstance()
{
    if (!instance)
        instance = new ScriptManager();
    return instance;
}

ScriptManager* ScriptManager::instance = NULL;

void ScriptManager::update(float dt)
{
    for (Script* script : scripts)
    {
        script -> update(dt);
    }
};

void ScriptManager::addScript(GameObjectComponent* addingOfScript)
{
    scripts.push_back(static_cast<Script*>(addingOfScript));
}

void ScriptManager::removeScript(GameObjectComponent* removingOfScript)
{
    for (int i = 0; i < scripts.size(); i++)
    {
        if (scripts[i] == removingOfScript)
        {
            scripts.erase(scripts.begin() + i);
        }
    }
}
