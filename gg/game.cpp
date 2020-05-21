#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <type_traits>
#include "user_api.h"
#include <cmath>


class MoveByKeys:public Script
{ 
	void execute() override;
};

void MoveByKeys::execute()
{
	float displacement = 0.2;
	/*if ((this->obj->x < -300) or (this->obj->x > 300))
	{
		//this->obj->x = 0;
		displacement = -displacement;
	}
	if ((this->obj->y < -300) or (this->obj->y > 300))
	{
		//this->obj->y = 0;
		displacement = -displacement;
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->obj->x += displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->obj->x -= displacement;
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->obj->y += displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->obj->y -= displacement;*/
}

//void MakeAnimationByKeys::execute() 





class CustomCollider:public Collider{
	void onCollision() override{
//		std::cout << "Collision!" << std::endl;
	}
	~CustomCollider(){};
};

class Player
{
public:
	std::string name;
	std::string file_name;
	Player(std::string obj_name, std::string file_name, float vx, float vy);
	~Player();
};

Player::Player(std::string obj_name, std::string file_name, float vx, float vy)
{
	this->name = obj_name;
	this->file_name = file_name;
	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
    ge::makeAnimation(this->name, 0, 0, 62.6, 89, 5, 0.01);
	ge::addComponent<CustomCollider>(this->name);
	std::vector<std::pair<float, float>> vec;
	float x;
	float y;
	x = - 200;
	y = -200;

	ge::Vertex v = ge::Vertex(vec);
	ge::makeModelOfCollider<CustomCollider>(v, this->name);
	ge::setCoordinates(this->name,{x,y});
	ge::setVelocity(this->name, vx, vy);
	//ge::addComponent<MoveAnimationByKeys>(this->name);
	
}
Player::~Player()
{
	ge::deleteObject(this->name);
}

class Background
{
	public:
	std::string name;
	std::string file_name;
	Background(std::string obj_name, std::string file_name, float vx, float vy);
	~Background();
};

Background::Background(std::string obj_name, std::string file_name, float vx, float vy)
{
	this->name = obj_name;
	this->file_name = file_name;
	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
	ge::addComponent<MoveByKeys>(this->name);
}

Background::~Background()
{
	ge::deleteObject(this->name);
}

class Cristal
{
	public:
	std::string name;
	std::string file_name;
	Cristal(std::string obj_name, std::string file_name, float x, float y);
	~Cristal();
};

Cristal::Cristal(std::string obj_name, std::string file_name, float x, float y)
{
	this->name = obj_name;
	this->file_name = file_name;
	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
	ge::makeAnimation(this->name, 0, 0, 32, 32, 8, 0.02);
	ge::setCoordinates(this->name, {x, y});
	ge::addComponent<MoveByKeys>(this->name);
}
Cristal::~Cristal()
{
	ge::deleteObject(this->name);
}


int main()
{
	ge::setWindowTitle("Works!");
	ge::setWindowSize(600, 600);

	

	/*std::vector<std::pair<float, float>> vec;
	float x, y, vx, vy;
	ge::createObject("player");
	ge::addComponent<Renderer>("player");
	ge::makeSprite("player", "player_big.png");
	ge::makeAnimation("player", 0, 0, 62.6, 89, 5, 0.02);
	ge::addComponent<CustomCollider>("player");
	ge::Vertex v = ge::Vertex(vec);
	ge::makeModelOfCollider<CustomCollider>(v, "player");
	x = -200;
	y = -200;
	ge::setCoordinates("player",{x,y});
	ge::addComponent<MoveByKeys>("player");*/
	Background back = Background("back", "sizeLevel3(4).jpg", 0, 0);
	Player p = Player("player", "player_big.png", 0, 0);
	Cristal c1 = Cristal("cristal", "cristal.png",  250, -200);
	

	
	ge::runApplication();
	return 0;
}
