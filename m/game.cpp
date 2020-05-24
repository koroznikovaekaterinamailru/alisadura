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
	float displacement = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->obj->x += displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->obj->x -= displacement;
}

class CustomCollider:public Collider{
	void onCollision() override
	{
		//std::cout << "Collision!" << std::endl;
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

	float x;
	float y;
	x=-200;
	y=-200;

	ge::setCoordinates(this->name,{x,y});
	ge::setVelocity(this->name, vx, vy);
	std::vector<std::pair<float, float>> vec;
    vec.push_back({x+1, y});
	vec.push_back({x+1, y+1});
	vec.push_back({x-1, y});
	vec.push_back({x-1, y-1});
	ge::Vertex v = ge::Vertex(vec);
	ge::makeModelOfCollider<CustomCollider>(v, this->name);
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
	Background(std::string obj_name, std::string file_name, float x, float y);
	~Background();
};


Background::Background(std::string obj_name, std::string file_name, float x, float y)
{
	this->name = obj_name;
	this->file_name = file_name;
	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
	ge::addComponent<MoveByKeys>(this->name);
	ge::setCoordinates(this->name,{x,y});	
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

	std::vector<std::pair<float, float>> vec;

	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
	ge::makeAnimation(this->name, 0, 0, 32, 32, 8, 0.02);
	ge::setCoordinates(this->name, {x, y});
	ge::addComponent<MoveByKeys>("cristal");
	ge::addComponent<CustomCollider>("cristal");

    vec.push_back({x+1, y});
	vec.push_back({x+1, y+1});
	vec.push_back({x-1, y});
	vec.push_back({x-1, y-1});

    ge::Vertex v = ge::Vertex(vec);
    ge::addComponent<CustomCollider>("cristal");
    ge::makeModelOfCollider<CustomCollider>(v, "cristal");
    ge::setMoveable<CustomCollider>("cristal", true);
}
Cristal::~Cristal()
{
	ge::deleteObject(this->name);
}


class CristalCount
{
	public:
	std::string name;
	std::string file_name;
	CristalCount(std::string obj_name, std::string sobj_name, float x, float y);
	~CristalCount();
};

CristalCount::CristalCount(std::string obj_name, std::string sobj_name, float x, float y)
{
	this->name = obj_name;
	this->file_name = "";

	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::setText(this->name, x, y, sobj_name);
	ge::setCoordinates(this->name, {x, y});

}

CristalCount::~CristalCount()
{
	ge::deleteObject(this->name);
}


class PlayerLife
{
	public:
	std::string name;
	std::string file_name;
	PlayerLife(std::string obj_name, std::string sobj_name, float x, float y);
	~PlayerLife();
};

PlayerLife::PlayerLife(std::string obj_name, std::string sobj_name, float x, float y)
{
	this->name = obj_name;
	this->file_name = "";

	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::setText(this->name, x, y, sobj_name);
	ge::setCoordinates(this->name, {x, y});
}

PlayerLife::~PlayerLife()
{
	ge::deleteObject(this->name);
}


class Enemy
{
	public:
	std::string name;
	std::string file_name;
	Enemy(std::string obj_name, std::string sobj_name, float x, float y);
	~Enemy();
};

Enemy::Enemy(std::string obj_name, std::string file_name, float x, float y)
{
	this->name = obj_name;
	this->file_name = file_name;
	ge::createObject(obj_name);
	ge::addComponent<Renderer>(this->name);
	ge::makeSprite(this->name, this->file_name);
	ge::makeAnimation(this->name, 0, 0, 63.75, 52, 4, 0.02);
	ge::setCoordinates(this->name,{x,y});	
	ge::addComponent<MoveByKeys>(this->name);
	ge::addComponent<CustomCollider>(this->name);
	std::vector<std::pair<float, float>> vec;

    vec.push_back({x+1, y});
	vec.push_back({x+1, y+1});
	vec.push_back({x-1, y});
	vec.push_back({x-1, y-1});

    ge::Vertex v = ge::Vertex(vec);
    ge::addComponent<CustomCollider>(this->name);
    ge::makeModelOfCollider<CustomCollider>(v, this->name);
    ge::setMoveable<CustomCollider>(this->name, true);
}

Enemy::~Enemy()
{
	ge::deleteObject(this->name);
}


int main()
{
	ge::setWindowTitle("Super mario, girls edition!");
	ge::setWindowSize(600, 600);

	Background back = Background("back", "sizeLevel3(4).jpg", 1700, 0);
    Player player = Player("player", "player_big.png", 0, 0);
	Cristal cristal = Cristal("cristal", "cristal.png",  (rand() % 10) , -200);
	Enemy e = Enemy("enemy", "enemy.png",  200, -200);
	Cristal cristalNumber = Cristal("cristalNumber", "cristal.png", -250, 270);
	CristalCount cristalCount = CristalCount("cristalCount", "cristalCount", -235, 285);
	PlayerLife pl = PlayerLife("playerLife", "playerLife", 50, 285);
	ge::runApplication();
	return 0;
}
