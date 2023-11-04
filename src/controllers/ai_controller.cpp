#include "ai_controller.h"
#include <SFML/Window.hpp>

#include <vector>
#include <algorithm>


AIController::AIController(b2Body *body)
  : body(body) {}

AIController::~AIController() {}

int AIController::getCondMove()
{
    return condMove;
}

void AIController::update() {
    body->ApplyForceToCenter(b2Vec2(0.0f, -100.0f), true);
}
