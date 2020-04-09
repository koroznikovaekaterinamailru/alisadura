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
        static GraphicsManager* getInstance();
        void addObject(GameObjectComponent* addingOfRenderer);
        void removeObject(GameObjectComponent* removingOfRenderer);
        void drawAllObjects(sf::RenderWindow& window);

    private:
        std::vector<Renderer*> drawable_obj; 
        sf::RenderWindow* window;
        static GraphicsManager* instance;
};

GraphicsManager* GraphicsManager::getInstance()
{
    if (!instance)
        instance = new GraphicsManager();
    return instance;
}

void GraphicsManager::addObject(GameObjectComponent* addingOfRenderer)
{
    drawable_obj.push_back(static_cast<Renderer*>(addingOfRenderer));
};

void GraphicsManager::removeObject(GameObjectComponent* removingOfRenderer)
{
    for (int i = 0; i < drawable_obj.size(); i++)
    {
        if (drawable_obj[i] == removingOfRenderer)
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

GraphicsManager* GraphicsManager::instance = NULL;

#endif // DRAWMANAGER_H
