#ifndef SCRIPTS_H
#define SCRIPTS_H
#include "game_object.h"

class ScriptManager
{
	public:
        static ScriptManager* getInstance();        
	    void update(float dt);
	    void addScript(GameObjectComponent* addingOfScript);
	    void removeScript(GameObjectComponent* removingOfScript);

	private:
        static ScriptManager* instance;
	    std::vector<Script*> scripts;
};

#endif // SCRIPTS_H
