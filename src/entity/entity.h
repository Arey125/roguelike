#include <box2d/b2_body.h>
#include <functional>

#include "shared/game_object.h"
#include "shared/controller.h"

class Entity: public GameObject {
public:
    Entity(b2World &world, std::function<Controller *(b2Body *)> createController);
    ~Entity();

    virtual void render(sf::RenderTarget &target) override;
    virtual void update() override;

    // for test purposes
    void testContact(b2Contact *contact);

private:
  sf::ConvexShape shape;
  b2Body *body;
  Controller* controller;
  bool contact = false;
};
