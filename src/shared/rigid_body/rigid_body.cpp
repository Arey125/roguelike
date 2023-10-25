#include "rigid_body.h"

#include <utility>

RigidBody::RigidBody(sf::ConvexShape shape, b2Body* body, sf::RenderTarget* renderTarget):
    shape(std::move(shape)), body(body), renderTarget(renderTarget) {}

void RigidBody::update() {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    shape.setRotation(angle * 180 / 3.14159f);
    shape.setPosition({position.x, position.y});
}

void RigidBody::render(/*sf::RenderTarget &target*/) {
    //target.draw(shape);
    renderTarget->draw(shape);
}

