#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

#include <box2d/b2_body.h>
#include <functional>

#include "shared/game_object.h"
#include "shared/controller.h"

class Tile: public GameObject
{
public:
    Tile(b2World& world, float X, float Y, 
         unsigned int size, 
         bool isWay = true);
    

    sf::Texture* texture;

    sf::Sprite& getSprite();

    virtual void render(/*sf::RenderTarget &target*/) override;
    virtual void update() override;

    void setIsWay(bool v);
    bool getIsWay();

    void setColor(const sf::Color& color);                      
    const sf::Color& getColor();

    ~Tile();

private:
    // w,h
    unsigned int size;

    sf::Vector2f pos;

    bool isWay;
    sf::Color* color;

    sf::Sprite sprite;

    b2PolygonShape* Shape;

    void buildBody(b2World& world);
};

#endif //TILE_H
