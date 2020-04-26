#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2f imageCount, float switchTime);
	~Animation();
	sf::IntRect Rect;
	void UpdateRow(int row, float deltaTime, bool faceRight);
	void Update(float deltaTime);

private:
	sf::Vector2f imageCount;
	sf::Vector2f currentImage;
	float totalTime;
	float switchTime;
};


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

void Animation::UpdateRow(int row, float deltaTime,bool faceRight)
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
	
	Rect.left = currentImage.x*Rect.width;
	Rect.top = currentImage.y*Rect.height;
}

void Animation::Update( float deltaTime)
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
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Demo Game");

	sf::Event event;
	sf::RectangleShape player;
	player.setSize(sf::Vector2f(300.0f, 300.0f));
	player.setPosition(76.0f, 76.0f);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("images/explosion.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2f(4, 4), 0.1f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
	    while (window.pollEvent(event))
	    {
	        if (event.type == sf::Event::EventType::Closed)
	            window.close();
	    }

		//animation.UpdateRow(0, deltaTime);
		player.setTextureRect(animation.Rect);
		animation.Update(deltaTime);

		window.clear();
	    window.draw(player);
	    window.display();

	    
    }
    return 0;
}
