#include "gr_manager.h"

GraphicsManager* GraphicsManager::getInstance()
{
    if (!instance)
        instance = new GraphicsManager();
    return instance;
}
GraphicsManager* GraphicsManager::instance = NULL;

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

