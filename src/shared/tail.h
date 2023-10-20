#ifndef TAIL_H
#define TAIL_H

#include "SFML/Graphics.hpp"

#include <box2d/b2_body.h>
#include <functional>

#include "shared/game_object.h"
#include "shared/controller.h"

class Tail: public GameObject
{
public:
    Tail(b2World& world, float X, float Y, bool isWay = true);
    ~Tail();

    sf::Sprite& getShape();

    virtual void render(sf::RenderTarget &target) override;
    virtual void update() override;

    void setIsWay(bool v);
    bool getIsWay();

    void setColor(const sf::Color& color);                      
    const sf::Color& getColor();
private:
    bool isWay;
    sf::Color* color;

    sf::Sprite sprite;

    b2PolygonShape* Shape;

    void buildBody(b2World& world, float X, float Y);
};

#endif //TAIL_H