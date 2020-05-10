# GRL Engine API Documentation


"GRL Engine" is an engine and it works. Here you can find all information how to exploit it.

# New Features!

 
  - there will be new features)))))))))


## Components

#### grl::Renderer
This component of your object is responsible for graphics. 
#### grl::Script

#### grl::Collider
## Data Storage
```sh
class DataStorage
{
    public:
	    bool createObject(std::string name, GameObject* object);
		bool deleteObject(std::string name);
		GameObject* getObject(std::string name);
        static DataStorage* getInstance();
	private:
        static DataStorage* instance;
		std::map<std::string, GameObject*> objects;
};
```
## Managers
In our engine we use only necessary managers to control all the components of your object:
- Graphics Manager
- Physics Manager
- Script Manager

### Graphics Manager
```sh 
class GraphicsManager
{
    public:
        static GraphicsManager* getInstance();
        void addRenderer(GameObjectComponent* addingOfRenderer);
        void removeRenderer(GameObjectComponent* removingOfRenderer);
        void drawAllObjects(sf::RenderWindow& window);

    private:
        static GraphicsManager* instance;
        std::vector<Renderer*> drawable_obj; 
        sf::RenderWindow* window;
};
```

### Physics Manager
```sh 
class PhysicsManager
{
    public:
        static PhysicsManager* getInstance();
        void addCollider(GameObjectComponent* addingOfCollider);
        void removeCollider(GameObjectComponent* removingOfCollider);
        bool isCollision(Collider* object1 , Collider* object2);
        void allCollisions();

    private:
        static PhysicsManager* instance;
        std::vector <Collider*> collidingObjects;
};
```

### Script Manager
```sh 
class ScriptManager
{
	public:
        static ScriptManager* getInstance();        
	    void update(float dt);
	    void addScript(GameObjectComponent* addingOfScript);
	    void removeScript(GameObjectComponent* removingOfScript);

	private:
        static ScriptManager* instance;
	    std::vector<Script*> scripts;
};
```

# Messenger
Also you can chat with us in the future. Follow us:)
This kind of messenger you haven't seen before.

To understand how it works, let's open three terminals. So
the first terminal is a server
the second is the first client
the third is the second client

Let's turn now to the first terminal. Here we have to start the server. In the econd and the third terminals we have to write the client's names.

SO, AFTER THAT, YOU ARE IN OUR CHAT!!!!!
CONGRATULATIONS

### Server.h
This code has an array of clients that cling to it. There is also a function that processes an incoming paket from a client.
### Server.cpp
Let's see to int main()
```sh
int main()
{
Server server(53000);
server.run();
return 0;
}
```
The server is created here on a specific port. Then the server starts working.
How does the server start? You don't know??? So, let's we explain you.
A socket is created and then it looks are there any clients here.
A NEW SOCKET IS MADE FOR EACH CLIENT!
### PacketType.h
PacketType has some types of packets:
the first packet: The client says: "Hey, hello guys! I exist!"
the second packet: the message from the client
the third paket: sending messages from server

```sh
const PacketType INITIAL_NAME_DATA=0;
const PacketType GENERAL_MSG=1;
const PacketType SERVER_MSG=2;
```

### Code Example
GRL Engine is very simple. But you add whatever you want. Here is a code example with a "hero" and a "monster" of how to use it.



```sh
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

```
