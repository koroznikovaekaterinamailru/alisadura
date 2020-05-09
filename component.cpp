#include <SFML/Graphics.hpp>
#include <string>
#include "game_object.h"
#include "component.h"

////////////////////////////////////

void Renderer::draw(sf::RenderWindow& window)
{
    sprite.setPosition( owner->position.x, owner->position.y );
    window.draw(sprite);
}
////////////////////////////////////
Script::Script(){
    this->name = typeid(Script).name();
}

Animation::Animation(sf::Texture* texture, sf::Vector2f imageCount, float switchTime)
	{
		this->imageCount = imageCount;
		this->switchTime = switchTime;
		totalTime = 0.0f;
		currentImage.x = 0;

		Rect.width = texture->getSize().x/float(imageCount.x);
		Rect.height = texture->getSize().y/float(imageCount.y);
	}


Animation::~Animation()
{

}

void Animation::UpdateRow(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;

		}
	}
	
	Rect.top = currentImage.y*Rect.height;
	if (faceRight)
	{
		Rect.left = currentImage.x*Rect.width;
		Rect.width = abs(Rect.width);
	}
	else
	{
		Rect.left = (currentImage.x+1)*abs(Rect.width);
		Rect.width = -abs(Rect.width);
	}
};

void Animation::Update(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
			currentImage.y++;
		}
		if (currentImage.y >= imageCount.y)
		{
			currentImage.y = 0;

		}
	}
	
	Rect.left = currentImage.x*Rect.width;
	Rect.top = currentImage.y*Rect.height;
};


void Renderer::createAnimation(sf::Texture* texture, sf::Vector2f imageCount, float switchTime, float deltaTime)
{
	Animation animation(texture, imageCount, switchTime);
	animation.Update(deltaTime);
};


