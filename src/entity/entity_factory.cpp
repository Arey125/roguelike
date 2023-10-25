#include "entity_factory.h"
#include "controllers/ai_controller.h"
#include "controllers/input_controller.h"
#include "controllers/create_controller.h"


EntityFactory* EntityFactory::instance = nullptr;

EntityFactory* EntityFactory::Instance()
{
    if (instance == nullptr)
    {
        instance = new EntityFactory(new b2World({0, 0}));
    }

    return instance;
}

b2World* EntityFactory::getWorld()
{
    return world;
}

EntityFactory::EntityFactory(b2World* world)
    : world(world) {}


Entity* EntityFactory::createPlayer(sf::RenderWindow* window) {
    return new Entity(world, createController<InputController>, window);
}

Entity* EntityFactory::createEntity(sf::RenderWindow* window) {
    return new Entity(world, createController<AIController>, window);
}
