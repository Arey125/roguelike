#include "tile.h"

#include <box2d/box2d.h>
#include "controllers/input_controller.h"

#include <iostream>

Tile::Tile(b2World& world, float X, float Y, unsigned int size_, bool isWay_): 
    isWay(isWay_), size(size_)
{
    color = new sf::Color;
    texture = new sf::Texture;

    pos.x = X;
    pos.y = Y;

    if (!isWay)
    {
        buildBody(world);

        texture->loadFromFile("wall1.png", 
                             sf::IntRect(0,0,size,size));
    }
    else
    {
        texture->loadFromFile("way2.jpg", 
                             sf::IntRect(0,0,size,size));
    }

    sprite.setTexture(*texture);

    //sprite.setOrigin(0.f, 0.f);
    sprite.setPosition(pos.x, pos.y);
}

void Tile::buildBody(b2World& world)
{
    b2BodyDef BodyDef;
    BodyDef.position.Set(pos.x + (size/2), pos.y + (size/2));

    BodyDef.type = b2_staticBody; 
    b2Body* Body = world.CreateBody(&BodyDef);

    Shape = new b2PolygonShape;
    Shape->SetAsBox((size/2.f), (size/2.f));

    Body->CreateFixture(Shape, 1.0);
}

sf::Sprite& Tile::getSprite()
{
    return sprite;
}

void Tile::setIsWay(bool v)
{
    isWay = v;
}

bool Tile::getIsWay()
{
    return isWay;
}

void Tile::setColor(const sf::Color& color_)
{
    *color = color_;
}

const sf::Color& Tile::getColor()
{
    return *color;
}

void Tile::update()
{
   
}

void Tile::render(/*sf::RenderTarget &target*/)
{
    
}

Tile::~Tile()
{
    delete color;
    delete texture;
}