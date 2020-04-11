# GRL Engine API Documentation


"GRL Engine" is an engine and it works. Here you can file all useful information how to exploit it.

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


### Code Example
GRL Engine is very simple. But you add whatever you want. Here is a code example with a "hero" and a "monster" of how to use it.



```sh
#include "GRL_API.h"
const float dt = 0.5;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "GRL");
    DataStorage* dataStorage = DataStorage::getInstance();
    GraphicsManager* GrManager = GraphicsManager::getInstance();
    ScriptManager* ScrManager = ScriptManager::getInstance();
    PhysicsManager* PhManager = PhysicsManager::getInstance();

    GameObject hero;
    hero.addComponent<Renderer>();
    hero.getComponent<Renderer>()->loadTexture("hero.jpg");
    hero.getComponent<Renderer>()->createSprite();
    hero.setPosition(300,300);
    dataStorage->createObject("hero", &hero);

    GameObject monster;
    monster.addComponent<Renderer>();
    monster.getComponent<Renderer>()->loadTexture("monster.jpg");
    monster.getComponent<Renderer>()->createSprite();
    monster.setPosition(600,100);
    dataStorage->createObject("monster", &monster);

    sf::Event event;
    while (window.isOpen())
	{
       // ScrManager->update(dt);
        window.clear(sf::Color(0,0,0));
        GrManager->drawAllObjects(window);

        window.display();

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

```

