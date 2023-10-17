#include "tail.h"

#include <box2d/box2d.h>
#include "controllers/input_controller.h"

Tail::Tail(bool isWay_): isWay(isWay_)
{
    color = new sf::Color;
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