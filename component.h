#ifndef COMPONENT_H
#define COMPONENT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <typeinfo>

    class GameObject;

    class GameObjectComponent//создание класса компонент
    {
        public:
            std::string name;
            GameObject* owner;
    };

    class Renderer : public GameObjectComponent //отрисовка
    {
        public:
            class Animation;
            Renderer()
            {
                name = typeid(*this).name();
            };
            void draw(sf::RenderWindow& window);
            void loadTexture(std::string textureName)
            {
                texture.loadFromFile(textureName);
            };
            void createSprite()
            {
                sprite.setTexture(texture);
            };
            void createSpriteRect(sf::IntRect Rect)
            {
                sprite.setTextureRect(Rect);
            };
            sf::Sprite* getSprite()
            {
                return &sprite;
            };

            sf::Texture* getTexture()
            {
                return &texture;
            };
            float totalTime;
            float switchTime;
            void createAnimation(sf::Texture* texture, sf::Vector2f imageCount, float switchTime, float deltaTime);
            
            virtual void update(float dt) {};



        private:
            sf::Texture texture;
            sf::Sprite sprite;
            

    };
   

    class Collider: public GameObjectComponent
    {
        public:
            Collider();
            bool isCollision();
            float width;//ширина прямоугольника,в котором содержится объект
            float height;//высота прямоугольника,в котором содержится объект
            float x;
            float y;
        private:
            std::vector<std::vector <float> > object_coordinate; //(координаты прямоугольника,в котором содержится объект)
    };

    class Script : public GameObjectComponent
    {
        public:
            Script();
            virtual void update(float dt) {}
             bool faceRight;
     
    };



    class Animation : public Renderer
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
        
    };

#endif // COMPONENT_H
