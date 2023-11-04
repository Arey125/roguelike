#pragma once

#include <box2d/b2_world.h>
#include "entity.h"


class EntityFactory {
public:
    static EntityFactory* Instance();

    Entity* createPlayer(sf::RenderWindow* window);
    Entity* createEntity(sf::RenderWindow* window);

    b2World* getWorld();

protected:
    EntityFactory(b2World* world);

private:
    b2World* world;

    // Единственный экземляр класса
    static EntityFactory* instance;
};
