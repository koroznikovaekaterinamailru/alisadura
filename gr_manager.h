#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game_object.h"

class GraphicsManager
{
    public:

        bool addObject(GameObjectComponent* remove_renderer);
        bool removeObject(GameObjectComponent* add_renderer);
        void drawAllObjects(sf::RenderWindow& window);

    private:

        GraphicsManager() {}
        //std::map<std::string, GameObject*> drawable_obj;
                std::vector<Renderer*> drawable_obj; 
        sf::RenderWindow* window;
};

bool GraphicsManager::addObject(GameObjectComponent* add_renderer)
{
    try
    {
        drawable_obj.push_back(static_cast<Renderer*>(add_renderer));
        return true;
    }
    catch(...)
    {
        return false;
    }
};

  bool GraphicsManager::removeObject(GameObjectComponent* remove_renderer)
{
    for (int i = 0; i < drawable_obj.size(); i++)
    {
        if (drawable_obj[i] == remove_renderer)
        {
            drawable_obj.erase(drawable_obj.begin() + i);
            return true;
        }
    }
    return false;
};

void GraphicsManager::drawAllObjects(sf::RenderWindow& window)
{
    for (Renderer* renderer : drawable_obj)
    {
        renderer-> draw(window);
    }
    window.display();
};

#endif // DRAWMANAGER_H
