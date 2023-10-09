#include <box2d/b2_body.h>

#include "shared/game_object.h"
#include "shared/controller.h"

class Entity: public GameObject {
public:
  Entity(b2World &world);
  virtual void render(sf::RenderTarget &target);
  virtual void update();

private:
  sf::ConvexShape shape;
  b2Body *body;
  std::unique_ptr<Controller> controller;
};
