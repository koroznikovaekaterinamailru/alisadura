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

