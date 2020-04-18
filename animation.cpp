#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2f imageCount, float switchTime);
	~Animation();
	sf::IntRect uvRect;
	void Update(int row, float deltaTime);

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

		uvRect.width = texture->getSize().x/float(imageCount.x);
		uvRect.height = texture->getSize().y/float(imageCount.y);
	}


Animation::~Animation()
{

}

void Animation::Update(int row, float deltaTime)
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
	
	std::cout<<currentImage.x << currentImage.y <<std::endl;
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Demo Game");

	sf::Event event;
	sf::RectangleShape player;
	player.setSize(sf::Vector2f(200.0f, 200.0f));
	player.setPosition(206.0f, 206.0f);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("images/fighter.jpg");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2f(6, 4), 0.3f);
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

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear();
	    window.draw(player);
	    window.display();

	    
    }
    return 0;
}
