#include "gr_manager.h"
#include "script_manager.h"
#include "data_storage.h"
#include "physics_manager.h"
#include "cmath"


const float dt = 0.1;


class Controller: public Script
{
public:
    float speed = 1;

    Controller()
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

class MonsterAI: public Script
{
    public:
        float speed = 1;
        float cooldown = 0;

    MonsterAI()
    {
        name = typeid(*this).name();
    }

    void update(float dt)
    {
        DataStorage* data_storage = DataStorage::getInstance();

        GameObject* hero = data_storage->getObject("hero");

        float rx = hero->position.x - owner->position.x;
        float ry = hero->position.y - owner->position.y;

        float distance = sqrt(rx*rx + ry*ry);

        rx /= distance;
        ry /= distance;

        owner->position.x += rx * speed * dt;
        owner->position.y += ry * speed * dt;

        cooldown -= dt;
        if ((cooldown <= 0) and (distance <= 20))
        {
            std::cout << "collision" << std::endl;
            cooldown = 5;
        }
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
    hero.addComponent<Controller>();
    dataStorage->createObject("hero", &hero);

    GameObject monster;
    monster.addComponent<Renderer>();
    monster.getComponent<Renderer>()->loadTexture("monster_s.png");
    monster.getComponent<Renderer>()->createSprite();
    monster.setPosition(600,100);
    monster.addComponent<MonsterAI>();
    dataStorage->createObject("monster", &monster);

    sf::Event event;
    while (window.isOpen())
	{
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);
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
    delete ScrManager;
    delete PhManager;
    return 0;
}
