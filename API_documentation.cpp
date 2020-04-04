objectAPI:
	void createObject(std::string name)
	GameObject& getObject(std::string name)
	void deleteObject(std::string name)

GameObject:    
	void setPosition(int x, int y); 
	template <typename T>
	T* addComponent()
	T* getComponent()
	T* removeComponent()

GameObjectComponent:

	Renderer:
		void draw(sf::RenderWindow& window);
	    void loadTexture(std::string texture_name);   
	    void createSprite();

	Collider:
	    bool isCollision();
	    void allCollisions();
	        
	Script:
		virtual void update(float dt);
