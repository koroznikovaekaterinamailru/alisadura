#include <SFML/Graphics.hpp>
#include <vector>

class DrawableObj
{
  public:
      virtual void draw(sf::RenderWindow* pointer);  
      DrawableObj();
      ~DrawableObj();
};

class GraphicsManager
{
public:
    GraphicsManager();

    void drawObject(sf::DrawableObj& object);
    void drawAllObjects(sf::RenderWindow* pointer);

    void addRenderer(Renderer* renderer);
    void removeRenderer(Renderer* renderer);

    void clear();
};

