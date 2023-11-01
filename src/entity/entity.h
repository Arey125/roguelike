#pragma once

#include <box2d/b2_body.h>
#include <functional>

#include "shared/game_object.h"
#include "shared/controller.h"

class Entity: public GameObject {
public:
    Entity(b2World* world, std::function <Controller* (b2Body*)> createController,
           sf::RenderWindow* renderWindow);

    ~Entity();

    const b2Vec2& getPosition();

    virtual void render(/*sf::RenderTarget &target*/) override;
    virtual void update() override;

    // for test purposes
    void testContact(b2Contact *contact);

    int getCondMove();

private:
    sf::ConvexShape shape;
    b2Body *body;
    Controller* controller;

    sf::RenderWindow* pWindow;

    float angleMove;

    // for test purposes
    bool contact = false;
};
