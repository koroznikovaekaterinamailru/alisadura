#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game_object.h"

class GameObject;

/*class DrawableObj
{
  public:
      virtual void draw();  
      DrawableObj();
      ~DrawableObj();
};*/

class GraphicsManager
{
	public:

		sf::RenderWindow* getWindow();

	    void drawAllObjects(sf::RenderWindow& window);
	    bool addObject(std::string name , GameObject* obj);
	    bool removeObject(std::string name);
	    void clear();

    private:

        GraphicsManager() {}
        std::map<std::string, GameObject*> drawable_obj;
        sf::RenderWindow* window;
};

sf::RenderWindow* GraphicsManager::getWindow()
{
    return window;
}

void GraphicsManager::drawAllObjects(sf::RenderWindow& window)
{
    for (auto& object : drawable_obj)
    {
        object.second->getComponent<Renderer>()->draw(window);
    }
    window.display();
};

bool GraphicsManager::addObject(std::string name , GameObject* obj)
{
    if(drawable_obj[name] = obj)
    {
        return true;
    }
    return false;
};

bool GraphicsManager::removeObject(std::string name)
{
    if(drawable_obj.count(name) == 1)
    {
        delete drawable_obj[name];
        drawable_obj.erase(name);
        return true;
    }
    return false;
};
