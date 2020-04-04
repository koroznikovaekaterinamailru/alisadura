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

        void addObject(GameObjectComponent* remove_renderer);
        void removeObject(GameObjectComponent* add_renderer);
        void drawAllObjects(sf::RenderWindow& window);

    private:
        std::vector<Renderer*> drawable_obj; 
        sf::RenderWindow* window;
};

void GraphicsManager::addObject(GameObjectComponent* add_renderer)
{
    drawable_obj.push_back(static_cast<Renderer*>(add_renderer));
};

void GraphicsManager::removeObject(GameObjectComponent* remove_renderer)
{
    for (int i = 0; i < drawable_obj.size(); i++)
    {
        if (drawable_obj[i] == remove_renderer)
        {
            drawable_obj.erase(drawable_obj.begin() + i);
        }
    }
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
