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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->obj->x -=30;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->obj->x +=30;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->obj->y +=30;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->obj->y -=30;
}

class CustomCollider:public Collider{
	void onCollision() override{
//		std::cout << "Collision!" << std::endl;
	}
	~CustomCollider(){};
};

int main(){
	ge::setWindowTitle("Works!");
	ge::setWindowSize(600, 600);

	ge::createObject("back");
	ge::addComponent<Renderer>("back");
	ge::makeSprite("back", "back2.png");

	std::vector<std::pair<float, float>> vec;
	float x, y, vx, vy;
	ge::createObject("horse");
	ge::addComponent<Renderer>("horse");
	ge::makeSprite("horse", "horse2.png");
	ge::makeAnimation("horse", 0, 0, 127.6, 205, 3, 0.02);
	ge::addComponent<CustomCollider>("horse");
	ge::Vertex v = ge::Vertex(vec);
	ge::makeModelOfCollider<CustomCollider>(v, "horse");

	x = -200;
	y = -200;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		x +=30;

	ge::setCoordinates("horse",{x,y});
	

	
	ge::runApplication();
	return 0;
}
