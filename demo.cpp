#include "gr_manager.h"
#include "script_manager.h"
#include "data_storage.h"
#include "physics_manager.h"
#include "cmath"


const float dt = 0.5;


class PlayerKeyboardMove: public Script
{
public:
    float speed = 2;

    PlayerKeyboardMove()
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
        float vel_y = 1;
        float vel_x =1;
        float cooldown = 0;

    MonsterMove()
    {
        name = typeid(*this).name();
    }

    void update(float dt)
    {
        DataStorage* data_storage = DataStorage::getInstance();

        GameObject* hero = data_storage->getObject("hero");

        float rx = owner->position.x;
        float ry =  owner->position.y;
        float hx = hero->position.x;
        float hy = hero->position.y;

        float distance = sqrt((rx-hx)*(rx-hx) + (ry-hy)*(ry-hy));

        rx /= distance;
        ry /= distance;

        owner->position.x += vel_x * dt;
        owner->position.y += vel_y * dt;

        if ((owner->position.x > 670) or (owner->position.x < 0))
            vel_x = - vel_x;
        if ((owner->position.y > 670) or (owner->position.y < 0))
           vel_y = - vel_y;

        cooldown -= dt;
        if ((cooldown <= 0) and (distance <= 40))
        {
            std::cout << "collision" << std::endl;
            cooldown = 5;
            vel_x = - vel_x;
            vel_y = - vel_y;
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
    hero.addComponent<PlayerKeyboardMove>();
    dataStorage->createObject("hero", &hero);

    GameObject monster;
    monster.addComponent<Renderer>();
    monster.getComponent<Renderer>()->loadTexture("monster_s.png");
    monster.getComponent<Renderer>()->createSprite();
    monster.setPosition(600,100);
    monster.addComponent<MonsterMove>();
    dataStorage->createObject("monster", &monster);

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
    delete ScrManager;
    delete PhManager;
    return 0;
}
