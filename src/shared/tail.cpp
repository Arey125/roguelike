#include "tail.h"

#include <box2d/box2d.h>
#include "controllers/input_controller.h"

#include <iostream>

const float SCALED = 30.f;

Tail::Tail(b2World& world, float X, float Y, bool isWay_): isWay(isWay_)
{
    color = new sf::Color;

    if (!isWay)
    {
        buildBody(world, X, Y);
    }
}

void Tail::buildBody(b2World& world, float X, float Y)
{
    b2BodyDef BodyDef;
    BodyDef.position.Set(X + 25, Y + 25);

    BodyDef.type = b2_staticBody; 
    b2Body* Body = world.CreateBody(&BodyDef);

    Shape = new b2PolygonShape;
    Shape->SetAsBox((50.f/2.f), (50.f/2.f));

    Body->CreateFixture(Shape, 1.0);

    sf::Texture* GroundTexture = new sf::Texture;
    GroundTexture->loadFromFile("wall1.png", 
                                sf::IntRect(0,0,50,50));

    sprite.setTexture(*GroundTexture, true);

    //sprite.setOrigin(0.f, 0.f);
    sprite.setPosition(Body->GetPosition().x-25, Body->GetPosition().y-25);
    //sprite.setRotation(180/b2_pi * Body->GetAngle());
}

sf::Sprite& Tail::getShape()
{
    return sprite;
}

void Tail::setIsWay(bool v)
{
    isWay = v;
}

bool Tail::getIsWay()
{
    return isWay;
}

void Tail::setColor(const sf::Color& color_)
{
    *color = color_;
}

const sf::Color& Tail::getColor()
{
    return *color;
}

void Tail::update()
{
   
}

void Tail::render(sf::RenderTarget &target)
{
    
}

Tail::~Tail()
{
    delete color;
}