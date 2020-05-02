#include "gr_manager.h"
#include "data_storage.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "girrrrrls");
    DataStorage* dataStorage = DataStorage::getInstance();
    GraphicsManager* GrManager = GraphicsManager::getInstance();
   // ScriptManager* ScrManager = ScriptManager::getInstance();
  //  PhysicsManager* PhManager = PhysicsManager::getInstance();

    GameObject hero;
    hero.addComponent<Renderer>();
    hero.getComponent<Renderer>()->loadTexture("hero.jpg");
    hero.getComponent<Renderer>()->createSprite();
    hero.setPosition(300,300);
    dataStorage->createObject("hero", &hero);
    //std::cout<<"hero added"<<std::endl;*/

    GameObject monster;
    monster.addComponent<Renderer>();
    monster.getComponent<Renderer>()->loadTexture("monster.jpg");
    monster.getComponent<Renderer>()->createSprite();
    monster.setPosition(300,100);
    dataStorage->createObject("monster", &monster);
    //std::cout<<"monster added"<<std::endl;

    sf::Event event;
    while (window.isOpen())
	{
       // ScrManager->update(dt);
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);
        window.display();

        //std::cout<<"window is displayed"<<std::endl;

        while (window.pollEvent(event))
	    {
            if (event.type == sf::Event::Closed){
                window.close();
            }
	    }
    }

    delete dataStorage;
    delete GrManager;
    return 0;
}
