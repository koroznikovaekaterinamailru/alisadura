#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game_object.h"
#include "component.h"

class GraphicsManager
{
    public:
        static GraphicsManager* getInstance();
        void addObject(GameObjectComponent* addingOfRenderer);
        void removeObject(GameObjectComponent* removingOfRenderer);
        void drawAllObjects(sf::RenderWindow& window);

    private:
        static GraphicsManager* instance;
        std::vector<Renderer*> drawable_obj; 
        sf::RenderWindow* window;
};

#endif // DRAWMANAGER_H
