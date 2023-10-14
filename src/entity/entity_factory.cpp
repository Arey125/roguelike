#include "entity_factory.h"
#include "controllers/ai_controller.h"
#include "controllers/input_controller.h"
#include "controllers/create_controller.h"


EntityFactory::EntityFactory(b2World &world)
    : world(world) {}


Entity EntityFactory::createPlayer() {
    return Entity(world, createController<InputController>);
}

Entity EntityFactory::createEntity() {
    return Entity(world, createController<AIController>);
}
