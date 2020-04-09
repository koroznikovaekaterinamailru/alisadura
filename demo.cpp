#include <SFML/Graphics.hpp>
#include "gr_manager.h"
#include "data_storage.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Some game");
    DataStorage* data_storage = DataStorage::getInstance();
    GraphicsManager* GrManager = GraphicsManager::getInstance();

    GameObject player;
    player.addComponent<Renderer>();
    player.getComponent<Renderer>()->loadTexture("bl3.png");
    player.getComponent<Renderer>()->createSprite();
    player.setPosition(300,300);
    data_storage->createObject("player", &player);


    sf::Event event;
    while (window.isOpen())
	{
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);

        while (window.pollEvent(event))
	    {
            if (event.type == sf::Event::Closed){
                window.close();
            }	   
	    }
    }
    delete data_storage;
    delete GrManager;
    return 0;
}
