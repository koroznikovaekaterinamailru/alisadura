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

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2f imageCount, float switchTime, float speed);
	~Player();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	};

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

};

Player::Player(sf::Texture* texture, sf::Vector2f imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);

}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += speed * deltaTime;
	}
	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 3;
		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}

	animation.UpdateRow(row, deltaTime, faceRight);
	body.setTextureRect(animation.Rect);
	body.move(movement);
};

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
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
}


static const float VIEW_HEIGHT = 512.0f;
void ResizeView(sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x)/ float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);

}


int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Demo Game", sf::Style::Close | sf::Style::Resize);
	sf::Event event;
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("images/ch003.png");
	Player player(&playerTexture, sf::Vector2f(4, 4), 0.1f, 100.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
	    while (window.pollEvent(event))
	    {
	        switch (event.type)
	        {
	        	case sf::Event::Closed:
	        		window.close();
	        		break;
	            case sf::Event::Resized:
	            	ResizeView(window, view);
	            	break;
	        }

	    }

		//animation.UpdateRow(0, deltaTime);
		player.update(deltaTime);
		view.setCenter(player.GetPosition());

		window.clear();
		window.setView(view);
	    player.draw(window);
	    window.display();

	    
    }
    return 0;
}