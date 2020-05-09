#include "gr_manager.h"
#include "script_manager.h"
#include "data_storage.h"
#include "physics_manager.h"

const float dt = 0.5;



int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "girrrrrls", sf::Style::Close | sf::Style::Resize);
    DataStorage* dataStorage = DataStorage::getInstance();
    GraphicsManager* GrManager = GraphicsManager::getInstance();
    ScriptManager* ScrManager = ScriptManager::getInstance();
    PhysicsManager* PhManager = PhysicsManager::getInstance();

    GameObject hero;
    hero.addComponent<Renderer>();
    hero.getComponent<Renderer>()->loadTexture("hero_s.png");
    hero.getComponent<Renderer>()->createSprite();
    hero.setPosition(300,300);
    hero.addComponent<KeyboardMove>();
    dataStorage->createObject("hero", &hero);
    //std::cout<<"hero added"<<std::endl;

    GameObject monster;
    monster.addComponent<Renderer>();
    monster.getComponent<Renderer>()->loadTexture("monster_s.png");
    monster.getComponent<Renderer>()->createSprite();
    monster.setPosition(200,100);
    monster.addComponent<MonsterMove>();
    dataStorage->createObject("monster", &monster);
    //std::cout<<"monster added"<<std::endl;


    GameObject explosion;
    explosion.addComponent<Renderer>();
    explosion.getComponent<Renderer>()->loadTexture("explosion.png");
    explosion.setPosition(200,100);
    dataStorage->createObject("explosion", &explosion);
    explosion.getComponent<Renderer>()->createSprite();
    explosion.getComponent<Renderer>()->createAnimation(explosion.getComponent<Renderer>()->getTexture(), sf::Vector2f(4, 4), 0.1f, dt);

    float deltaTime = 0.0f;
    sf::Clock clock;

    sf::Event event;

    while (window.isOpen())
	{
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);
        PhManager->allCollisions();
        window.display();
        ScrManager->update(dt);
        GrManager->update(dt);


        while (window.pollEvent(event))
	    {
            if (event.type == sf::Event::Closed){
                window.close();
            }
	    }
    }

    delete dataStorage;
    delete GrManager;
    delete PhManager;
    return 0;
}
