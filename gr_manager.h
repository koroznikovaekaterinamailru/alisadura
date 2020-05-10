#ifndef GRMANAGER_H
#define GRMANAGER_H
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

#endif // GRMANAGER_H
