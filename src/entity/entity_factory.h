#pragma once

#include <box2d/b2_world.h>
#include "entity.h"


class EntityFactory {
public:
    EntityFactory(b2World &world);

    Entity createPlayer();
    Entity createEntity();

private:
    b2World &world;
};
