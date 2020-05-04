#include "gr_manager.h"
#include "script_manager.h"
#include "data_storage.h"
#include "physics_manager.h"

const float dt = 0.5;


class KeyboardMove: public Script
{
public:
    float speed = 1;

    KeyboardMove()
    {
        name = typeid(*this).name();
    }

    void update(float dt)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            owner->position.x += speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            owner->position.x -= speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            owner->position.y += speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            owner->position.y -= speed * dt;
        }
    }
};

class MonsterMove: public Script
{
public:
    float speed = 0.5;
    MonsterMove()
    {
        name = typeid(*this).name();
    }
    void update(float dt)
    {
        owner->position.x += speed * dt;
        owner->position.y += speed * dt;
        if ((owner->position.x > 720) || (owner->position.x < 0))
            owner->position.x -= speed * dt;
        if ((owner->position.y > 720) || (owner->position.y < 0))
            owner->position.y -= speed * dt;
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "girrrrrls");
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

    sf::Event event;
    while (window.isOpen())
	{
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);
        PhManager->allCollisions();
        window.display();
        ScrManager->update(dt);

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
