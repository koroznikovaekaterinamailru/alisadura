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
	float displacement = 3;
	if ((this->obj->x < -300) or (this->obj->x > 300))
	{
		//this->obj->x = 0;
		displacement = -displacement;
	}
	if ((this->obj->y < -300) or (this->obj->y > 300))
	{
		//this->obj->y = 0;
		displacement = -displacement;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->obj->x -= displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->obj->x += displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->obj->y += displacement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->obj->y -= displacement;
}

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
	ge::makeAnimation(this->name, 0, 0, 62.6, 89, 5, 0.02);
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
	ge::addComponent<MoveByKeys>(this->name);
}
Player::~Player()
{
	ge::deleteObject(this->name);
}

int main()
{
	ge::setWindowTitle("Works!");
	ge::setWindowSize(600, 600);

	ge::createObject("back");
	ge::addComponent<Renderer>("back");
	ge::makeSprite("back", "back2.png");

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

	Player p = Player("player", "player_big.png", 0, 0);

	ge::createObject("cristal");
	ge::addComponent<Renderer>("cristal");
	ge::makeSprite("cristal", "cristal.png");
	ge::makeAnimation("cristal", 0, 0, 32, 32, 8, 0.02);
	float x_crystal = 100;
	float y_crystal = -200;
	ge::setCoordinates("cristal",{x_crystal,y_crystal});

	ge::runApplication();
	return 0;
}
