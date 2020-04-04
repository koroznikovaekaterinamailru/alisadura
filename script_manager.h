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
	    void update(float dt);
	    void addScript(GameObjectComponent* add_script);
	    void removeScript(GameObjectComponent* remove_script);

	private:
	    std::vector<Script*> scripts;
};

void ScriptManager::update(float dt)
{
    for (Script* script : scripts)
    {
        script -> update(dt);
    }
};

void ScriptManager::addScript(GameObjectComponent* add_script)
{
    scripts.push_back(static_cast<Script*>(add_script));
}

void ScriptManager::removeScript(GameObjectComponent* remove_script)
{
    for (int i = 0; i < scripts.size(); i++)
    {
        if (scripts[i] == remove_script)
        {
            scripts.erase(scripts.begin() + i);
        }
    }
}

ScriptManager* ScriptManager = NULL;

#endif // SCRIPTS_H
