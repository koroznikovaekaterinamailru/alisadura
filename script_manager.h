#ifndef SCRIPTS_H
#define SCRIPTS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game_object.h"

class ScriptManager
{
	public:
        static ScriptManager* getInstance();        
	    void update(float dt);
	    void addScript(GameObjectComponent* addingOfScript);
	    void removeScript(GameObjectComponent* removingOfScript);

	private:
	    std::vector<Script*> scripts;
        static ScriptManager* instance;
};

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

ScriptManager* ScriptManager = NULL;

#endif // SCRIPTS_H
